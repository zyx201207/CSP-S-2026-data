#include<bits/stdc++.h>
using namespace std;
int c,t,ans=0;
int f[2000005];
long long a[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int u=1;u<=t;u++){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++){
			f[i]=1;
			for(int j=i;j<=n;j++){
				for(int k=i;k<j;k++){
					if(a[j]-a[k]<=m) f[j]+=f[k];
				}
				if(f[j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
