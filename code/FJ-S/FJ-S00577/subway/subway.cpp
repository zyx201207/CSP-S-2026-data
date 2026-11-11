#include <bits/stdc++.h>
using namespace std;

struct type{
	int n;
	int s[25],t[25];
};

int c,n,m,d,q;
int w[500005];
type node[500005];
long long mapn[505][505];

int read(){
	int k = 0,f = 1,c = getchar();
	for(;!isdigit(c);c = getchar())
		if(c == '-')
			f = -1;
	for(;isdigit(c);c = getchar())
		k = k*10 + (c^48);
	return k*f;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i = 1;i <= 500;i++)
		for(int j = 1;j <= 500;j++)
			if(i != j)
				mapn[i][j] = 10000000000000;
	
	c = read(),n = read(),m = read(),d = read(),q = read();
	for(int i = 1;i <= m;i++)
		w[i] = read();
	for(int i = 1;i <= n;i++){
		int k = read(),a;
		for(int j = 1;j <= k;j++){
			a = read();
			node[a].n++;
			node[a].s[node[a].n] = i;
			node[a].t[node[a].n] = read();
		}
	}
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= node[i].n;j++)
			for(int k = 1;k <= node[i].n;k++)
				if(mapn[node[i].s[j]][node[i].s[k]] > node[i].t[j] + node[i].t[k])
					mapn[node[i].s[j]][node[i].s[k]] = node[i].t[j] + node[i].t[k]; 
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			for(int k = 1;k <= n;k++)
				if(mapn[j][k] > mapn[j][i] + mapn[i][k])
					mapn[j][k] = mapn[j][i] + mapn[i][k];
	for(int i = 1;i <= q;i++){
		long long minn = 10000000000000;
		int x = read(),y = read();
		for(int j = 1;j <= node[x].n;j++)
			for(int k = 1;k <= node[y].n;k++)
				if(minn > node[x].t[j] + mapn[node[x].s[j]][node[y].s[k]] + node[y].t[k])
					minn = node[x].t[j] + mapn[node[x].s[j]][node[y].s[k]] + node[y].t[k];
		printf("%lld\n",w[x] + minn + w[y]);
	}
	
	return 0;
}
