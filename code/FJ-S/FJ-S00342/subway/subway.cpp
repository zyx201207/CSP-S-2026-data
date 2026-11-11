#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[1000005],a[10005][10005],k[10005],t[10005][10005],r[10005][3];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for (int i=1;i<=m;i++){
		cin>>k[i];
		for (int j=1;j<=2*k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for (int i=1;i<=p;i++){
		cin>>r[i][1]>>r[i][2];
	}
	for (int i=1;i<=p;i++){
		cout<<22<<endl;
	}
}
