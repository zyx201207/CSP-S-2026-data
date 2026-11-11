#include <bits/stdc++.h>
using namespace std;
const int N=3e3+5;
int c,t;
long long n,a[N],d,f[N],g[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		if(n>3e3){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++){
			memset(f,0x3f,sizeof(f));
			memset(g,0,sizeof(g));
			f[i]=0;
			g[i]=1;
			for(int j=i+1;j<=n;j++){
				for(int k=j-1;a[j]-a[k]<=d && k>=i;k--){
//					cout<<g[k]<<" "<<g[j]<<" "<<k<<endl;
					if(f[k]+1<f[j]){
						f[j]=f[k]+1,g[j]=g[k];
					}else if(f[k]+1==f[j]){
						g[j]=(g[k]+g[j]);
						if(g[j]>=3) g[j]=3;
					}
				}
				if(g[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

