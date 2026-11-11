#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=0;
	for(int i=0;i<n;i++)
	{
		int h;
		cin>>h;
		if(h>maxn)
			maxn=h;
	}
	cout<<maxn;
	return 0;
}
