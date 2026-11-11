#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("card.in","r",stdin);
	//freopen("card1_ex.in","r",stdin);
	freopen("card.out","W",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[1000000],b[1000000],s1[1000000],s2[1000000];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s1[i] = i;
	}
	for(int k=1;k<=n;k++)
	{
		for(int j=1;j<=n;j++)
		{
			b[j] = 0;
		}
		for(int i=k;i<=n-k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(b[j] == a[i])
				{
					for(int i=j;i<=n-j;i++)
					{
						b[j] = 0;
					}
				}
				b[j] = a[i];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j = 1;i<=n;i++)
			{
				if(s1[i] == b[j])
				{
					s2[i]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<s2[i];
	}
	return 0;
}
