#include <bits/stdc++.h>
using namespace std;
bool f[5005][5005];
int a[5005];
int n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			int j=i;
			int fl=0;
			while(j<n&&a[j+1]-a[j]<=d){
				int gg=0;
				if(fl>=1)f[i][j]=1;
				fl++;
				while(gg+a[j+1]-a[j]<=d){
					if(j==n)break;
					gg+=a[j+1]-a[j];
					j++;
				}
			}
			j=i;
			fl=0;
			while(j>1&&a[j]-a[j-1]<=d){
				int gg=0;
				if(fl>=1)f[i][j]=1;
				fl++;
				while(gg+a[j]-a[j-1]<=d){
					if(j==1)break;
					gg+=a[j]-a[j-1];
					j--;
				}	
			}
			f[i][i]=0;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<f[i][j]<<' ';
				ans+=f[i][j+1];
			}cout<<'\n';
		} 
		cout<<ans<<'\n';
	}
	return 0;
}

