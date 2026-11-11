#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N];
int k[90][90][90];
int n,d;
void dfs(int x,int st,int dp){
	k[st][x][dp]++;
	if(x==n)return;
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]>d)return;
		else dfs(i,st,dp+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c>=0&&c<=2){
		while(t--){
			cin>>n>>d;
			memset(k,0,sizeof k);
			for(int i=1;i<=n;i++)cin>>a[i];
			for(int i=1;i<=n;i++)dfs(i,i,0);
			int res=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int z=1;z<n;z++){
						if(k[i][j][z]){
							if(k[i][j][z]==2){
								res++;
								break;
							}else{
								break;
							}
						}
					}
				}
			}
			cout<<res<<'\n';
		}
	}		
	return 0;
}

