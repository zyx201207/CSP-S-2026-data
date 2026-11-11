#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int w[500010];
int a[1001][100010];
int t[1001][100010];
int x[100010],y[100010];
vector<int> zhan[10001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}	
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	
	return 0;
}
