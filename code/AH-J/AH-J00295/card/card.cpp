#include<bits/stdc++.h>
using namespace std;
//nobody should be undefined
const int N=5e5+5,M=3e5+5;
int n,m,a[N],t[M],s[M];
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(t[a[j]]!=0)
			{
				for(int k=t[a[j]];k<=j;k++)
				{
					t[a[k]]=0;
				}
			}
			t[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(t[j]!=0)
			{
				++s[j];
			}
		}
		memset(t,0,sizeof(t));
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
}
/*10 3
3 1 2 1 3 2 3 1 2 1
* 4 3
1 2 1 3*/
