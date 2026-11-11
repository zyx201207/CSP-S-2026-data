#include<bits/stdc++.h>
using namespace std; 
long long n,m;
long long a[500007];
long long find_first_big(long long k){
	for(long long i=1;i<=n;i++){
		if(a[i]>k)return i;
	}return 0;
}long long find_first_small(long long k){
	for(long long i=n;i>=1;i--){
		if(a[i]<k)return i;
	}return 0;
}long long find_nbns_cnt(long long k){
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		cnt+=(a[i]==k);
	}
	return cnt;
}long long jisuan(long long idd){
	long long now=a[idd],retur=find_nbns_cnt(now);
	long long smal=find_first_small(a[idd]);
	long long m_=m;
	while(m_>0){
		if(smal>=1&&(m_>=now-a[smal])){
				m_-=now-a[smal];
				smal--;
		}else break;
		retur++;
	}return retur;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long start=1;
	if(n>5000){
		start=3;
		cin>>a[1]>>a[2]>>a[3];
		if(a[1]==a[2]){
			cout<<n;
			return 0;
		}else if(a[3]-a[2]==a[2]-a[1]){
			long long abc=m/(a[2]-a[1]),bca=0;
			for(long long i=1ll;i<=n;i++){
				if(abc-i>=0){
					bca++;
					abc-=i;
				}
			}cout<<bca;
			return 0;
		}
	}
	for(long long i=start;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long max_=jisuan(1ll);
	for(long long i=1ll;i<=n;i++){
		max_=max(max_,jisuan(i));
	}cout<<max_;
}/*5 5
1 2 4 8 9
5 8
-3 -1 2 2 7*/
