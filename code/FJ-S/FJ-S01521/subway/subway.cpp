#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[500005]a[500005],t[500005],x[100000],y[100000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	while(i<=n)
	{
		i++;
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++) cin>>a[j]>>t[j];
		if(a[i]%t[k[1]]==2*k[i+1]) cout<<a[k[i]]+t[i];
	}
	return 0;
}
