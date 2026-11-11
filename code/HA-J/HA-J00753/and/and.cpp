#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=1073741823,ma=-1;
bool b[200005];
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(n*m<=3*100000000)
	{
		for(int i=1;i<=m;i++)
		{
			int t=ans,pos=0,maxx=-1;
			for(int j=1;j<=n;j++)
			{
	//			cout<<t<<"&"<<a[j]<<" is "<<(t&a[j])<<" maxx:"<<maxx<<"\n";
				if((t&a[j])>maxx&&!b[j])
				{
					pos=j;
					maxx=(t&a[j]);
					
				}
			}
	//		cout<<a[pos]<<"\n";
			b[pos]=1;
			ans=maxx;
		}
		cout<<ans;
	}
	else
	{
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/
