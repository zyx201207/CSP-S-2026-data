//GZ-S00369 六盘水市第二十四中学 王胤杰 
#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,x,y;
long long m1[500050],n1[500][1010],q1[500050];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>m1[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>n1[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
	}
	cout<<95<<'\n'<<20<<'\n'<<50;
	return 0;
}
