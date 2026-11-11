#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int c,n,m,d,q;
int w[500001];
int K[501];
vector<int> a[501],t[501];
vector<pair<int,int>> p[500001];
ll f[501][501][501];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}for(int i=1;i<=n;i++){
		scanf("%d",&K[i]);
		for(int j=1;j<=K[i];j++){
			int a1,t1;
			scanf("%d%d",&a1,&t1);
			a[i].push_back(a1);
			p[a1].push_back({i,j-1});
			t[i].push_back(t1);
		}
	}for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				f[i][j][k]=1ll<<60;
			}
		}
	}for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			f[i][j][j]=0;
		}
	}for(int i=1;i<=m;i++){
		for(auto j : p[i]){
			for(auto k : p[i]){
				if(j==k){
					continue;
				}f[0][j.fi][k.fi]=min(f[0][j.fi][k.fi],(ll)t[j.fi][j.se]+t[k.fi][k.se]);
			}
		}
	}for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[k][i][j]=f[k-1][i][j];
				if(f[k-1][i][k]<1ll<<60&&f[k-1][k][j]<1ll<<60){
					f[k][i][j]=min(f[k][i][j],f[k-1][i][k]+f[k-1][k][j]);
				}
			}
		}
	}while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ll sum=1ll<<60;
		for(auto i : p[x]){
			for(auto j : p[y]){
				sum=min(sum,f[n][i.fi][j.fi]+t[i.fi][i.se]+t[j.fi][j.se]);
			}
		}if(sum==1ll<<60){
			assert(0);
		}sum+=w[x]+w[y];
		printf("%lld\n",sum);
	}
}