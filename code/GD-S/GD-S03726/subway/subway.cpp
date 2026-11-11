#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[500005],t[500005],k[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		cin>>a[i]>>t[i];
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<0<<"\n"; 
	}
	return 0;
} 
