#include<bits/stdc++.h>
using namespace std;
long long int p[1010101];
char k[1010101];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int sum=0;
	long long int n;
	cin>>n; 
	for(long long int i=1;i<=n;i++)
	{
		cin>>p[i];
		cin>>k[i];
	}
	long long int l=1,r=n;
	while(l<=r)
	{
		if(k[l]==k[r])
		{
			if(p[l]>p[r])
			{
				p[l]-=p[r];
				r--;
			}
			else
			{
				if(p[r]>p[l])
				{
					p[r]-=p[l];
					l++;
				}
				else
				{
					if(p[l]==p[r])
					{
						l++,r--;
					}
				}
			}
		}
		else
		{
			if(p[r]>p[l])
			{
				sum+=p[l];
				p[r]-=p[l];
				l++;
			}
			else
			{
				if(p[l]>p[r])
				{
					sum+=p[r];
					p[l]-=p[r];
					r--;
				}
				else
				{
					if(p[l]==p[r])
					{
						sum+=p[l];
						l++,r--;
					}
				}
			}
		}
	}
	cout<<sum;
}
/*
4
999 a
1 b
998 a
1 c
*/
