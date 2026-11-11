#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c,n,m,d,q;
int w[N],k[510];
int t[510][N];
int ans;
int l,r,u,v;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++) scanf("%d",&w[i]);
	for(int i = 1;i <= n;i++){
		scanf("%d",&k[i]);
		for(int j = 1;j <= k[i];j++){
			int a,b;scanf("%d%d",&a,&b);
			t[i][a] = b;
		}
	}
	while(q--){
		scanf("%d%d",&u,&v);
		if(u > v) swap(u,v);
		if(u < k[1]){
			l = 1,r = 0;
			if((v - k[1]) % (k[1] - 1) == 0) r = (v - k[1]) / (k[1] - 1) + 1;else r = (v - k[1]) / (k[1] - 1) + 2;
			if(l == r) ans = w[u] + t[l][u] + t[l][v] + w[v];
			else{
				ans = w[u] + t[l][u] + t[l][k[1] + (l - 1) * (k[1] - 1)];
				for(int j = l + 1;j <= r - 1;j++) ans += t[j][k[1] + (j - 2) * (k[1] - 1)] + t[j][k[1] + (j - 1) * (k[1] - 1)];
				ans += t[r][k[1] + (r - 2) * (k[1] - 1)] + t[r][v] + w[v];
			}
		}
		else if(u > k[1]){
			l = 0,r = 0;
			if((u - k[1]) % (k[1] - 1) == 0) l = (u - k[1]) / (k[1] - 1) + 1;else l = (u - k[1]) / (k[1] - 1) + 2; 
			if((v - k[1]) % (k[1] - 1) == 0) r = (v - k[1]) / (k[1] - 1) + 1;else r = (v - k[1]) / (k[1] - 1) + 2;
			if(l == r) ans = w[u] + t[l][u] + t[l][v] + w[v];
			else{
				ans = w[u] + t[l][u] + t[l][k[1] + (l - 1) * (k[1] - 1)];
				for(int j = l + 1;j <= r - 1;j++) ans += t[j][k[1] + (j - 2) * (k[1] - 1)] + t[j][k[1] + (j - 1) * (k[1] - 1)];
				ans += t[r][k[1] + (r - 2) * (k[1] - 1)] + t[r][v] + w[v];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
