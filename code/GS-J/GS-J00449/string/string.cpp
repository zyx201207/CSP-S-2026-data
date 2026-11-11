#include <bits/stdc++.h>
using namespace std;
long long l[2000];
char c[2000];
bool b[2000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
		cin>>c[i];
		sum+=l[i];
	}
	
	long long mid=sum/2;
	if(n==2)
	{
		if(c[1]!=c[2])
		{
			cout<<min(l[1],l[2]);
		}
		else{
			cout<<0;
		}
		
		return 0;
	}
	long long ans=0;
	long long flag=0;
	for(int i=1;i<=n;i++)
	{//判超过中间值的 
		if(l[i]>=mid)
		{
			cout<<sum-l[i]+ans;
			return 0;
		}
		if(l[n-i]>=mid)
		{
			cout<<sum-l[i-1]+ans;
			return 0;
		}
		
			
		}
	
	
	return 0;
}
