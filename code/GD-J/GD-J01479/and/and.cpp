#include<bits/stdc++.h>
using namespace std;
struct nd
{
	int d,e;
};
bool cmp(nd x,nd y)
{
	if(x.d==y.d)
	
		return x.e>y.e;
	return x.d>y.d; 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<nd> a(n);
	for(int i=0;i<n;i++)
	{
		int c;
		cin>>a[i].e;
		c=a[i].e;
		while(c)
		{
			a[i].d+=c%2;
			c/=2;
		}
	}
	sort(a.begin(),a.end(),cmp);
	int ans=a[0].e;
	for(int i=1;i<m;i++)
		ans=ans&a[i].e;
	cout<<ans;
	return 0;
}
