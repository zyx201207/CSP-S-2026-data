#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 50005;
const int M = 510;
int c,n,m,d,p;
ll w[N],k[M],a[M][N],t[M][N],ans;
vector<int>v[N];
void solve(int x,int y){
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
	for(int i = 1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i = 1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j = 1;j<=k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			if(j>=2){
				v[a[i][j-1]].push_back(a[i][j]);
				v[a[i][j]].push_back(a[i][j-1]);
			}
		}
	}
	while(p--){
		int x,y;
		ans = 0;
		scanf("%d%d",&x,&y);
		if(c>=7&&c<=11)solve(x,y);
		printf("%lld",ans);
	}
	return 0;
}
