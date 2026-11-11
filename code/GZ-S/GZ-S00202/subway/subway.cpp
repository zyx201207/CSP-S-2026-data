//GZ-S00202 贵阳市第一中学 薛子彦 
#include<iostream>
using namespace std;
int c,n,m,d,q,w[50010],k[500],a[500][50010],t[500][50010],x[100010],y[100010];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	return 0;
}
