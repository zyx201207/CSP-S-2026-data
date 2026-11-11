# include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[600000],k[600],a[600][600],t[600][600],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c;
	cin >>n>>m>>d>>q;//n-line-num  m-sub-num  d-line-most-pass q-plan-num
	for (int i=1;i<=m;i++)	cin >>w[i];
	for (int i=1;i<=n;i++){
		cin >>k[i];
		for (int j=1;j<=k[i];j++)
			cin >>a[i][j]>>t[i][j];
	}
	while(q--){
		cin >>x>>y;
		
		
	}
	return 0;
}
