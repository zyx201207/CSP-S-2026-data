#include <bits/stdc++.h>
using namespace std;
int w[500005];
int k[500005];
int a[500005];
int t[500005];
int x[500005];
int y[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int e=1;e<=max(c,1);e++){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i]>>t[i];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>x[i]>>y[i];
		}
		for(int i=1;i<=q;i++){
			cout<<x[i]<<y[i]<<"\n";
		}
	}
	
	
	return 0;
} 
