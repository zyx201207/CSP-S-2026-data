#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long p[500005];
bool cmp(long long a,long long b){
		return a<b;
}
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++){
		long long z=m;
		long long k=i,cnt=0,yzc=0;
		while(z>=0){
			long long pay=(p[k]-yzc)*cnt;
			if(pay<=z&&k<=n){
				//cout<<p[k]<<" "<<yzc<<" "<<cnt<<" "<<pay<<" "<<z<<" "<<endl;
				z-=pay;
				yzc=p[k];
				k++;
				cnt++;
			}else{
				break;
			}
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
	return 0;
}
