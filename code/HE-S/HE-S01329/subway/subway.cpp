#include <bits/stdc++.h>
using namespace std;
const int N=1e5*5+5;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[N]={};
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int a[55][55]={};
	int t[55][55]={};
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,sum=0;
		cin>>x>>y;
		sum+=w[x]+t[x][i]+w[y]+t[i][y];
		cout<<sum;
	}
	 
	return 0;
} 
