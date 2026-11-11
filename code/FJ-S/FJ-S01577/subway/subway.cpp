#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k, w[502], a[1002], t[1002], x, y, en[502][502], dis[502][502], ans[100002];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=m;j++){
			dis[i][j]=0x3f;
			en[i][j]=0x3f;}}
	for (int i=1;i<=m;i++){
		cin >> w[i];}
	for (int i=1;i<=n;i++){
		cin >> k;
		for (int j=1;j<=k;j++){
			cin >> a[j] >> t[j];
			for (int l=1;l<=j;l++){
				en[a[j]][a[l]]=t[j]+t[l];
				en[a[l]][a[j]]=t[j]+t[l];
				if (a[l]==a[j]){
					en[a[j]][a[l]]=0;
					en[a[l]][a[j]]=0;}}}}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=m;j++){
			for (int l=1;l<=m;l++){
				dis[i][j]=min(dis[i][j], en[i][l]+en[j][l]);}}}
	for (int i=1;i<=q;i++){
		cin >> x >> y;
		ans[i]=dis[x][y]+w[x]+w[y];}
	for (int i=1;i<=q;i++){cout << ans[i] << endl;}
	return 0;
}
