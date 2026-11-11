#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[10010],a[1010][10010],t[1010][10010],k[10010],x[10010],y[10010]; 
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++)
		cin>>x[i]>>y[i];
	while(q--){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				ans+=i*t[i][j];
			}
		}
		cout<<ans<<endl;                                                                                                          
	}
	return 0;
}
