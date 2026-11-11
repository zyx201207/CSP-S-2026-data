#include<bits/stdc++.h>
using namespace std;
const int N = 2000005;
long long x[N];
int c,T;
int n;
long long d;
bool vis[N];
long long p[N];
/*
void dfs(int x){
	if(x == n+1){
		
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			if(x == 1){
				vis[i] = 1;
				p[x] = i;
				dfs(x+1);
				vis[i]=0;
			}else{
				for(int j = x;j <= n;j++){
					if(!vis[i]){
						vis[i] = 1;
						p[x] = i;
						dfs(x+1);
						vis[i]=0;
					}			
				}
			}
			
		}
	}
	
}
*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d%lld",&n,&d);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&x[i]);
		}
		//dfs(1);
		printf("%d",n);
	}
	return 0;
}
