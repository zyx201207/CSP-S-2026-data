#include<bits/stdc++.h>
using namespace std;

long long n,m,mx = 0,sum = 1;
long long a[1000000],c[1000000],d[1000000],e[1000000],f[1000000],g[1000000],h[1000000],o[100000],p[100000];
long long b[1000000];

void dfs(long long k,int cc){
	int hh = cc,l = k;
	if(cc == 1){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				d[j] = c[j];
			}
			d[i]++;
			dfs(l-1,hh+1);
		}
	}
	else if(cc == 2&&k>0){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				e[j] = d[j];
			}
			e[i]++;
			dfs(l-1,hh+1);
		}
	}
	else if(cc == 4&&k>0){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				g[j] = f[j];
			}
			g[i]++;
			dfs(l-1,hh+1);
		}
	}
	else if(cc == 3&&k>0){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				f[j] = e[j];
			}
			f[i]++;
			dfs(l-1,hh+1);
		}
	}
	else if(cc == 5&&k>0){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				h[j] = g[j];
			}
			h[i]++;
			dfs(l-1,hh+1);
		}
	}
	else if(cc == 6&&k>0){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				o[j] = h[j];
			}
			h[i]++;
			dfs(l-1,hh+1);
		}
	}
	else if(cc == 7&&k>0){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				p[j] = o[j];
			}
			h[i]++;
			dfs(l-1,hh+1);
		}
	}
	if(k == 0&&cc == 2){
		for(int i = 1;i <= n;i++){
			while(d[i] == d[i+1] && i+1<=n){
				sum++;
				i++;
			}
			mx = max(sum,mx);
			sum = 1;
		}
		return ;
	}
	if(k == 0&&cc == 3){
		for(int i = 1;i <= n;i++){
			while(e[i] == e[i+1] && i+1<=n){
				sum++;
				i++;
			}
			mx = max(sum,mx);
			sum = 1;
		}
		return ;
	}
	if(k == 0&&cc == 4){
		for(int i = 1;i <= n;i++){
			while(f[i] == f[i+1] && i+1<=n){
				sum++;
				i++;
			}
			mx = max(sum,mx);
			sum = 1;
		}
		return ;
	}
	if(k == 0&&cc == 5){
		for(int i = 1;i <= n;i++){
			while(g[i] == g[i+1] && i+1<=n){
				sum++;
				i++;
			}
			mx = max(sum,mx);
			sum = 1;
		}
		return ;
	}
	if(k == 0&&cc == 6){
		for(int i = 1;i <= n;i++){
			while(o[i] == o[i+1] && i+1<=n){
				sum++;
				i++;
			}
			mx = max(sum,mx);
			sum = 1;
		}
		return ;
	}
	if(k == 0&&cc == 7){
		for(int i = 1;i <= n;i++){
			while(p[i] == p[i+1] && i+1<=n){
				sum++;
				i++;
			}
			mx = max(sum,mx);
			sum = 1;
		}
		return ;
	}
	return ;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		d[i] = a[i];
		c[i] = a[i];
	}
	if(m == 0){
		for(int i = 1;i <= n;i++){
			 if(a[i] == a[i+1]&&i+1<=n){
			 	while(a[i] == a[i+1]&&i+1 <= n){
			 		sum++;
			 		i++;
					mx = max(mx,sum);
				}
				sum = 0;
			}
		}
		cout<<mx;
		return 0;
	}
	dfs(m,1);
	cout<<mx;
	return 0;
}
