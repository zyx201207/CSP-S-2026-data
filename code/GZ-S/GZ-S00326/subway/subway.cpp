//GZ-S00326 遵义市南白中学 陈梓睿
#include <bits/stdc++.h>
#define ll long long
#define M 500050
using namespace std;
ll c,n,m,p,d,a[510][M],w[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i = 1;i<=m;i++) cin>>w[i];
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++){
			int mm,nn;
			cin>>mm>>nn;
			a[i][mm] = nn;
		}
	}
	return 0;
}


