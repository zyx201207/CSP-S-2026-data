#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int c,n,m,d,q;
int w[50000];
int k[510];
int a[510][50000];
int t[510][50000];
int qus[10000][3];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[k[i]][j];
		}
	}
	for(int i=1;i<=q+1;i++){
		int x,y;
		cin >> x >> y;
		int ans;
		ans+=w[x];
		ans+=w[y];
		cout << ans << endl;
	}
	return 0;
} 

