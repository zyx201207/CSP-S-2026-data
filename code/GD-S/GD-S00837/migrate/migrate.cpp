#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2000005;
int c,t,n,d,a[maxn],ans,f[maxn],ff[maxn];
signed mian(){
	ans=0;
	if(c>10){
		cout<<0;
		return 0;
	}
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i;
		memset(f,0,sizeof(f));
		memset(ff,0x3f,sizeof(ff));
		f[i]=ff[i]=1;
		for(int j=i+1;j<=n;j++){
			while(a[j]-a[l]>d){
				l++;
			}
			for(int k=l;k<j;k++){
				if(ff[k]+1<ff[j]){
					ff[j]=ff[k]+1;
					f[j]=0;
				}
				if(ff[k]+1==ff[j]){
					f[j]+=f[k];
				}
			}
			if(f[j]==2){
				ans++;
			}
			if(f[j]==0){
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		mian();
	}
	return 0;
} 
