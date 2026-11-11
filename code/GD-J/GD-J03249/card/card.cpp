#include <bits/stdc++.h>
using namespace std;
int c[200005],d[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005];
	vector<int> b;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		    c[j]=0;
		while(b.size()!=0)
		    b.pop_back();
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]]!=0)
			{
				int k=b.size()-1;
				while(b[k]!=a[j])
				{
					c[b[k]]-=1;
					b.pop_back();
					k--;
				}
				b.pop_back();
				c[b[k-1]]-=1;
			}
			b.push_back(a[j]);
			c[a[j]]++;
		}
		for(int j=1;j<=m;j++)
		{
			if(c[j]!=0)
			    d[j]++;
			c[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	    cout<<d[i]<<" ";
	return 0;
}
