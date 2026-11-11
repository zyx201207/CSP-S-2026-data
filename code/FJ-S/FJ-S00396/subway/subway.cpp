#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k[510],xq,yz,w[500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			long long a,t;
			cin>>a>>t;
		}
	}
	while(q--){
		cin>>xq>>yz;
		cout<<w[xq]+w[yz]<<endl;
	}
	return 0;
}
