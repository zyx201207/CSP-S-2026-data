#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long ans=0;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		ans+=w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[k][j]>>t[k][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		cout<<ans<<"\n";
	}
	return 0;
}
