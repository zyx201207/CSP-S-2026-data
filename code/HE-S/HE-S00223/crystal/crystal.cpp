#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long s[N],s1[N];
long long n,m,res=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=i;j<n;j++)
		{
			sum+=s[j];
			if(sum+m>=j*s[j+1])
			{
				s1[res++]=j+1;
			}
		}
	}
	int max=0;
	for(int i=0;i<=res;i++)
	{
		if(s1[i]>=max)
		max=s1[i];
	}
	cout<<max;
	return 0;
}
