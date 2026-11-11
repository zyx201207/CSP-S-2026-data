#include<bits/stdc++.h>
using namespace std;
int sum[300005],a[500005];
string s1,s2;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s1+=a[i]+'0';
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[j]==a[k])
				{
					s2=s1.substr(0,j-1)+s1.substr(k-1,n-k+1);
					j=k;
					break;
				}
				else s2=s1.substr(i-1,n-i+1);
			}
		}
		if(i==n) 
		{
			sum[a[i]]++;
			break;
		}
		for(int j=0;j<s2.size();j++)
		{
			sum[s2[j]-'0']++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
