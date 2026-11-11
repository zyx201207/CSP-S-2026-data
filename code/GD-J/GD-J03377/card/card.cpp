#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int ss=i;ss<=n;ss++)
		{
			s[a[i]]++;
		}
		for(int j=i;j<=n;j++)
		{
			for(int k=i;k<=j;k++)
			{
				if(a[k]==a[j])
				{
					for(int l=k;l<=j;l++)
					{
						s[a[l]]--;
					}
				}
			} 
		}
		if(s[i]!=0)
		{
			b[i]++;
		} 
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	return 0;
} 
