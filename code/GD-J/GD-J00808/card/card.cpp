#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long a[100001],b[100001];
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[i]==a[j])
			{
				for(int p=i;p<j;p++)
				{
					b[a[p]]--;
				}
			}
		}
		for(int k=i;k<=n;k++)
		{
			b[a[k]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	} 
	return 0;
}  
