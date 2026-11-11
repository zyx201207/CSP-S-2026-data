#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>p>>q;
	vector<int>a(m);
	for(iunbt i=0;i<m;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<q;i++)
	{
		cout<<a[i]*m/n;
	}
	return 0;
} 
