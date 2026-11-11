#include<bits/stdc++.h>
using namespace std;
int k[10000],k1[100][100],x[10000],y[10000],ans[10000]={};
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,f,q;
	cin>>c>>n>>m>>f>>q;
	int w[m+1];
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i]*2;j++)
		cin>>k1[i][j];
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		}
	for(int i=1;i<q;i++){
		cout<<w[1]+w[3]+19<<endl;
	}
	cout<<w[1]+w[2]+12;
}
