#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e6+10;
ll n,m,minn[N],sum[N],w[N],ans;
void kto(){
	ans=0;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>w[i];
	sort(w+1,w+1+n);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			sum[j]=0;
			minn[j]=1000000000;
		}sum[i]=1;
		minn[i]=0;
		for(ll j=i+1;j<=n;j++){
			for(ll k=j-1;k>=i;k--){
				if(w[j]-w[k]>m)break;
				if(minn[j]>minn[k]+1){
					minn[j]=minn[k]+1;
					sum[j]=sum[k];
				}else if(minn[j]==minn[k]+1){
					sum[j]+=sum[k];
				}
			}if(sum[j]==2)ans++;
		}
	}cout<<ans<<endl;
}int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		kto();
	}
	return 0;
}
