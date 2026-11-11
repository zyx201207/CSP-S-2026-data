#include<bits/stdc++.h>
using namespace std;
int a[200101],b[200101];
vector<int> f[41];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i1=1;i1<=n;i1++)
	{
		cin>>a[i1];
		int l=a[i1];
		for(int i2=0;l;i2++,l/=2)
			if(l%2)
				f[i2].push_back(i1);
	}
	int c;
	for(int i1=40;i1>=0;i1--)
		if(f[i1].size()>=m)
		{
			c=i1;
			for(int i2=0;i2<f[i1].size();i2++)
				b[i2]=a[f[i1][i2]];
			break;
		}
	sort(b,b+f[c].size());
	int d=b[f[c].size()-1];
	for(int i1=1;i1<=m;i1++)
		d=d&b[f[c].size()-i1];
	cout<<d;
	return 0;
}
