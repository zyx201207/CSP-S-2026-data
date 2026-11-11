#include<bits/stdc++.h>
using namespace std;
int g[2000000][2000000],c,t,f,x[200000+5],n,d,k,ans=0;
int main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		k=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f=abs(x[j]-x[i]);
				if(f>d) g[i][j]=0;
				else g[i][j]=1;
			}
		}
		for(int i=4;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				k=0;
				for(int k=j+1;k<=j+i-2;k++){
					if(g[j][k]&&g[k][j+i-1]) k++;
				}
				if(k==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	
}
