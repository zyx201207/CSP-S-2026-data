#include<bits/stdc++.h>
using namespace std;
long long n;long long a[200005];long long sum;long long cnt[200005];long long m;long long i1;long long l,r,cnt1,cnt2;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++) cnt[i]=cnt[i-1]+a[i];
	m=cnt[n]/2+cnt[n]%2;
	for(int i=1;i<=n;i++){
		if(m>=cnt[i]) i1=i+1;
	}
	l=i1,r=i1,cnt1=m-cnt[i1-1]-cnt[n]%2,cnt2=cnt[i1]-m;
	while(l>0&&r<=n){
		if(cnt1==cnt2){
			if(c[l]!=c[r]) sum+=cnt1;
			l--,r++;
			cnt1=a[l],cnt2=a[r];
		}
		else if(cnt1>cnt2){
			if(c[l]!=c[r]) sum+=cnt2;
			cnt1-=cnt2,r++,cnt2=a[r];
		}
		else{
			if(c[l]!=c[r]) sum+=cnt1;
			cnt2-=cnt1,l--,cnt1=a[l];
		}
	}
	cout<<sum;
	return 0;
}
