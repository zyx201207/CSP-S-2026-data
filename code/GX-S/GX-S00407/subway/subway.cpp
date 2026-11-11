#include<bits/stdc++.h>
using namespace std;
int m,c,n,d,q,w[500005],a[505][50005],t[505][50005],k[505],x[100005],y[100005],zh[50005][505];
int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			
			cin>>a[i][j]>>t[i][j];
			zh[a[i][j]][i]=t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		int mt=0;
		mt+=w[x[i]]+w[y[i]];
		for(int j=1;j<=n;j++){
			if(zh[x[i]][j]&&zh[y[i]][j])mt+=zh[y[i]][j]+zh[x[i]][j];
		}
		cout<<mt<<endl;
	}
	
    return 0;
}

