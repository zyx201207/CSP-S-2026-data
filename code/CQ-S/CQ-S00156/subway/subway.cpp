#include<bits/stdc++.h>
using namespace std;
long long w[500005],x[500005],y[500005];
long long sa[505][100005],st[505][100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>sa[i][j]>>st[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		for(int i=1;i<=n;i++){
			for(int i=1;i<=n;i++){
				int k;
				cin>>k;
				for(int j=1;j<=k;j++){
					cin>>sa[i][j]>>st[i][j];
				}
			}
		}
	}
	
	return 0;
}
