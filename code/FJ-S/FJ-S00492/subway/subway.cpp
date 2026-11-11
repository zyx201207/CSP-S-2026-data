#include <bits/stdc++.h>
using namespace std;
long long c,n,m,x,y,d,q,w[100005],k[100005],a[1005][1005],t[1005][1005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int j=1;j<=k[x];j++){
			if(a[x][j]==y){
				cout<<0<<endl;
				break;
			}
		}
	}
	return 0;
}
