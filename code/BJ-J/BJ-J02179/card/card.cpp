#include<bits/stdc++.h>
using namespace std;
int a[100010],ans[100010],t[100010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=n;j++)
	{
		vector<int> st;
		int len=0;
		for(int i=j;i<=n;i++)
		{
			if(!t[a[i]])
			{
				st[++len]=a[i];
				t[a[i]]=len;
			}
			else
			{
				for(int k=t[a[i]];k<=len;k++)
					st[k]=0;
				len=t[a[i]];
				st[len]=t[a[i]];
				t[a[i]]=len;
			}
		}
		for(int i=1;i<len;i++)
			ans[i]++;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}