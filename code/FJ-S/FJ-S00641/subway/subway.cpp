#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long c,n,m,d,q,w[N],dp[505][505],a[N],t[N];
long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f = -f;
		c = getchar();
	}
	while(isdigit(c)){
		x = (x<<3)+(x<<1)+(c^48);
		c = getchar();
	}
	return x*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++) dp[i][i] = 0;
	for(int i=1;i<=m;i++) w[i] = read();
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a[j] >> t[j];
			for(int l=1;l<j;l++){
				dp[a[l]][a[j]] = min(dp[a[l]][a[j]],t[l]+t[j]);
				dp[a[j]][a[l]] = min(dp[a[j]][a[l]],t[l]+t[j]);
			}
		}
	}
	for(int u=1;u<=m;u++){
		for(int v=1;v<=m;v++){
			for(int k=1;k<=m;k++){
				dp[u][v] = min(dp[u][v],dp[u][k]+dp[k][v]);
			} 
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << dp[x][y]+w[x]+w[y] << '\n';
	}
	return 0;
}
