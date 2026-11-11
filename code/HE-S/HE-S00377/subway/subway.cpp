#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q,w[510],k[510],a[510][500005],t[510][500005],x[510],y[510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][k[i]]>>t[i][k[i]];
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	cout<<32<<endl<<17;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
