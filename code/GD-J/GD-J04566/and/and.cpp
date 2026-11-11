#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n, m, x, k, s, g[N], f[N], a[N][35];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &g[i]);
		x=g[i];
		for(int j=0; j<=30; j++){
			if(x&1) a[i][j]=1;
			x>>=1;
		}
	}
	for(int i=30; i>=0; i--){
		k=0;
		for(int j=1; j<=n; j++){
			if(f[j]) continue;
			if(a[j][i]==1) k++;
		}
		if(k>=m){
			for(int j=1; j<=n; j++){
				if(!a[j][i]) f[j]=1;
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(!f[i]){
			s=g[i];
			break;
		}
	}
	for(int i=1; i<=n; i++){
		if(!f[i]) s&=g[i];
	}
	printf("%d", s);
	return 0;
} 
