#include<bits/stdc++.h>
using rnamespace std;
long long c,n,m,d,q;
long long w[500005];
long long k[500][1000005];
int main(){
	ios::sync_with_stdio;
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k1;
		cin>>k1;
		k[i][1]=k1;
		for(int j=2;j<=2*k1;i++){
			cin>>k[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x1,y1;
		cin>>x1>>y1;
		
	}
	return 0;
}
