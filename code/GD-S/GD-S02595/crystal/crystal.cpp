#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],answ;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=0)
		{
			int b[500005];
			for(int j=1;j<=n;j++)
			{
				b[j]=a[i]-a[j];
			}
			sort(b+1,b+1+n);
			int t=m,ans=0;
			for(int j=1;j<=n;j++)
			{
				if(t<=0)
				{
					break;
				}
				if(b[j]>=0&&t>=b[j])
				{
				t-=b[j];
				ans++;
				}
			}
			answ=max(answ,ans);
		}
	}
	cout<<answ;
	return 0;
}
