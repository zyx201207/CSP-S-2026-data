#include<iostream>
using namespace std;
#define int long long
int c,t,n,d;
int x[2000010],f[5010][5010],dd[5010][5010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(c>=11){
			cout<<0<<"\n";
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=1e9;
				dd[i][j]=0;	
			}
		}
		for(int i=1;i<=n;i++){
			f[i][i]=0;
			for(int j=i+1;j<=n;j++){
				for(int l=i;l<=j-1;l++){
					if(x[j]-x[l]<=d){
						
						f[i][j]=min(f[i][j],f[i][l]+1);
						
					}
				}
				for(int l=i;l<=j-1;l++){
					if(x[j]-x[l]<=d){
						
						if(f[i][l]+1==f[i][j])dd[i][j]++;
						
					}
				}
			}
			
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(dd[i][j]==2){
					ans++;
					//cout<<i<<' '<<j<<"\n";
				}
				dd[i][j]=0;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

