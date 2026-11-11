//GZ-S00153 遵义市播州区新蓝学校 王天垚
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int x[q+1],y[1+q];
	int w[m+1];
	for(int i=1;i<=m;i++) cin>>w[i];
	int a[n+1][1000],t[n+1][1000];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
}
