#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
int a[500][N],t[500][N],w[N],k[N];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);cout.tie(0);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	
	//cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		scanf("%d",&w[i]);
	}
	for(int i = 1;i <= n;i++){
		scanf("%d",&k[i]);
		for(int j = 1;j <= k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	
	
	while(q--){
		int x,y;
		int ans = 0;
		scanf("%d%d",&x,&y);
		for(int i = 1;i <= n;i++){
			int ans1 = w[x]+w[y];
			for(int j = 1;j <= k[i];j++){
				if(a[i][j] == x){
					ans += t[i][j];
				}
				//
				if(a[i][j] == y){
					ans += t[i][j];
				}
			}
			ans = max(ans,ans1);
		}
		printf("%d\n",ans);
	}
	
	
	return 0;
}
