#include<bits/stdc++.h>
using namespace std;
const int M=5e5,Q=1e5;
int c,n,m,d,q,w[M],x[Q],y[Q];
int main()
{
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	return 0;
}
