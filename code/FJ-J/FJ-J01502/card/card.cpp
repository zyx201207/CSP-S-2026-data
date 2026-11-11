#include <bits/stdc++.h>
int n,m;
int res[500000];
int x[500000];
int idx=0;
int y[500000];
char z[500000];
int game() {
	memset(y,0,500000*sizeof(int));
	memset(z,0,500000*sizeof(char));
	for(int i=idx; i<n; i++) {
		int j=i-idx;
		y[j] = x[i];
		int k1=j;
		if(z[y[j]]) {
			for(int k=0; k<j; k++) if(y[k] == y[j]) k1=k;
			memset(y+k1,0,sizeof(char)*(j-k1+1));
			memset(y+k1,0,sizeof(int)*(j-k1));
			y[k1]=x[i];
		}
		z[y[k1]]=1;
	}
	for(int i=0; i<n; i++) {
		if(z[i] <= m) res[y[i]]++;
	}
}


int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::cin>>n>>m;
	for(int i=0; i<n; i++) {
		scanf("%d",&x[i]);
	}

	for(int i=0; i<n; i++) {
		game();
		idx++;
	}

	for(int i=0; i<=m; i++) {
		printf("%d ",res[i]);
	}
}//zygisk neozygisk zygisknext nyazygisk yukizygisk rezygisk
