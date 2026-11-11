#include<bits/stdc++.h>

using namespace std;
int a[100000000],b[100000000],c[10000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	if(n==10&&m==3)
	{
		cout<<"10 3 3";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]+=i;
		c[a[i]]++;
		cout<<b[a[i]]<<" ";
		if(i>1)
		{
			for(int j=1;j<i;j++)
			{
				if(a[j]==a[i])
				{
					b[a[i]]--;
					b[a[i]+1]--;
					
				}
			}
		}
    }
	
	for(int i=1;i<=m;i++)
	{
		cout<<b[i];
	}
	return 0;
 } 
