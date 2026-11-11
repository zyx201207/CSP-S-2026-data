#include<bits/stdc++.h>
using namespace std;
#define int long  long
int a[1005][1005];
unsigned int x[1000086]; 
int vis[1005][1005];
int ans=0;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){	int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=n;j++)a[i][j]=1e18,vis[i][j]=0;
		for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++){
        	for(int j=i+1;j<=n;j++){
        		if(abs(x[j]-x[i])<=d)a[i][j]=a[j][i]=1;
        		else break;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<=j;k++){
					int now=a[i][k]+a[k][j];
					if(a[i][j]==now){
					  vis[i][j]++;
					}
					if(a[i][j]>now){
						vis[i][j]=1;
						a[i][j]=now;
					}
					
				}
			}
			
		}
		ans=0;
		for(int i=1;i<=n;i++)
		  for(int j=i+1;j<=n;j++)if(vis[i][j]==2)ans++;
		  cout<<ans<<endl;		
	}
	return 0;
}
/*

0 2
 4 2
 1 2 3 4
 5 2
 1 2 3 4 5


0 2
 5 3
 -2 -1 0 1 2
 6 2
 -4 -3 -2 -1 3 6





*/
