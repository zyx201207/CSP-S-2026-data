#include<bits/stdc++.h>
using namespace std;
long long ans;
int c,t,n,d;
int a[5010];
int f[5010][5010],cnt[5010][5010];

void dfs(int x,int tmp,int root){
	if(x>n)return ;
	//if(tmp == f[root][x])cout<<root<<' '<<x<<' '<<tmp<<endl;
	if(tmp == f[root][x])cnt[root][x]++;
	for(int i = 1;i<=d;i++){
		dfs(x+i,tmp+1,root);
	}
	
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	while(t--){
		ans = 0;
		memset(cnt,0,sizeof(cnt));
		memset(f,0x3f,sizeof(f));
		scanf("%d%d",&n,&d);
		for(int i = 1;i<=n;i++){
			scanf("%d",&a[i]);
			//for(int j = 1;j<=n;j++)cnt[i][j] = 1;
		}
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				if(a[i]+d>=a[j])f[i][j] = 1;
			}
		}
		for(int len = 3;len<=n;len++){
			for(int i = 1;i<=n;i++){
				int tmp = 0;
				int j = min(n,i+len-1);
				for(int k = i+1;k<j;k++){
					if(f[i][k]+f[k][j]<f[i][j]){
						f[i][j] = f[i][k]+f[k][j];
					}
				}
				
			}
		}
		
		//f[i][j]: the shortest road from i to j
		for(int i = 1;i<=n;i++)dfs(i,0,i);
		
		/*
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				cout<<i<<' '<<j<<' '<<cnt[i][j]<<endl;
			}
			cout<<endl;
		}
		*/
		
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				//cout<<cnt[i][j]<< ' ';
				if(cnt[i][j] == 2)ans++;
			}
			//cout<<endl;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
