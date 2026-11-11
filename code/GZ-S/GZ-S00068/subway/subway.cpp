// GZ-S00068 清镇市第一中学 蒋煜
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010];
int a[500010][500010],t[500010][500010];
void bfs(int a,int b){

}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++){
		cin >> w[i];
	}
	int tt=0;
	int k;
	for(int i = 1;i<=n;i++){
		cin >> k;
		for(int j = 1;j<=k;j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1;i<=k;i++){
        int x,y;
        cin >> x >> y;
        bfs(x,y);
	}
	cout << tt;
	return 0;
}
