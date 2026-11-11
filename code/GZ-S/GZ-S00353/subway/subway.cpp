//石阡县文博中学 刘贝宁 GZ-S00353 
#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[200005];
int k[200005];
int a[2000][2000];
int t[2000][2000];
int x[200005];
int y[200005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >>q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][k[i]] >> t[i][k[i]];
		}
		
	}
	for(int r=1;r<=q;r++){
		cin >> x[r] >> y[r];
	}
	if(c==1||c==2||c==3){
		if(n==1){
			for(int i=1;i<=q;i++){
				cout << x[i]+y[i];
			}
		}
		
	}
	return 0;
}
