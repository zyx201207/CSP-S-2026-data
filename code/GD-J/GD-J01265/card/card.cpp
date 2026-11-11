#include<bits/stdc++.h>
using namespace std;
int n,m,a[int(5e5+7)],s[int(3e5+7)],c;
struct ca
{
	int t;
	bool b;
};
ca d[int(5e5+7)];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
//		int i=1;
		c=0;
		for(int j=i;j<=n;j++)
		{
			bool w=0;
			for(int k=1;k<=c;k++)
			{
				if(d[k].t==a[j])
				{
					w=1;
//					cout<<k;
				}
				if(w)
				{
					d[k].b=1;
				}
			}
			d[++c].t=a[j];
		}
		for(int j=1;j<=c;j++)
		{
			if(!d[j].b)
			{
				s[d[j].t]++;
//				cout<<d[j].t<<endl;
			}
			d[j].b=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
}
