#include <bits/stdc++.h>
using namespace std;
const long long MX=1e9+7;
int c, n, m, d, q;
int w[500005];
int k[505];
int a[501][500001], t[501][500001];
int st, ed;
long long ans=0;
long long bian[404][404];
int dian, dians;
void solve(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			bian[i][j]=MX;
		}
		bian[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				dian=a[i][j], dians=a[i][l];
				bian[dian][dians]=bian[dians][dian]=min(bian[dians][dian], 1LL*(t[i][j]+t[i][l]));
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j)continue;
			for(int l=1;l<=m;l++){
				if(l==i||l==j)continue;
				bian[i][j]=bian[j][i]=min(bian[i][j], bian[i][l]+bian[l][j]);
			}
		}
	}
	while(q--){
		scanf("%d%d", &st, &ed);
		ans=w[st]+w[ed];
		ans+=bian[st][ed];
		printf("%lld\n", ans);
	}
	return ;
}
void solve2(){
	int flg=-1;
	while(q--){
		scanf("%d%d", &st, &ed);
		ans=0;
		flg=-1;
		for(int i=1;i<=n;i++){
			if(k[i]<2)continue;
			if(a[i][1]==st||a[i][2]==st){
				if(a[i][1]==ed||a[i][2]==ed){
					if(flg==-1){
						flg=1;
						ans=t[i][1]+t[i][2];
					}else{
						ans=min(ans, 1LL*(t[i][1]+t[i][2]));
					}
				}
			}
		}
		ans=ans+w[st]+w[ed];
		printf("%lld\n", ans); 
	}
	return ;
}
void solve3(){
	while(q--){
		scanf("%d%d", &st, &ed);
		ans=w[st]+w[ed];
		
	}
	
	return ; 
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i=1;i<=m;i++){
		scanf("%d", &w[i]);
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d", &k[i]);
		sum+=k[i];
		for(int j=1;j<=k[i];j++){
			scanf("%d%d", &a[i][j], &t[i][j]);
		}
	}
	if(sum<=400){
		solve();
		return 0;
	}
	if(sum>400&&sum<=1000){
		solve2();
		return 0;
	}
	if(n>200&&n<=500){
		solve3();
		return 0;
	}
	while(q--){
		scanf("%d%d", &st, &ed);
		ans=w[st]+w[ed];
		
	}
    return 0;
}

