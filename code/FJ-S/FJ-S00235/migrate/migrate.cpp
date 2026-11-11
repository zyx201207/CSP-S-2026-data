#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define maxn 2000010
int last[maxn][22], first[maxn][22];
bool plast[maxn][22], pfirst[maxn][22];
ll x[maxn];
int query(int x, int y){
	if(x == y) return 0;
	int sum = 0;
	for(int i=21;i>=0;i--){
		if(last[x][i] < y){
			x = last[x][i];
			sum+=(1<<i);
		}
	}
	return sum+1;
}
int main(){
	int c, t, n, l;
	ll d;
	scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%lld", &n, &d);
		l = 1;
		for(int r=1;r<=n;r++){
			scanf("%lld", &x[r]);
			while(x[r]-x[l] > d) {
				last[l++][0] = r-1;
			}
			first[r][0] = l;
			last[l][0] = r;
		}
		while(l<=n){
			last[l++][0] = n;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=21;j++){
				last[i][j] = last[last[i][j-1]][j-1];
				first[i][j] = first[first[i][j-1]][j-1];
				
			}
		}
	}
	return 0;
}
