#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,c=1,v=0;
	cin>>n>>m;
	int d[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
	}
	for(int i=n;i>=1;i--)
	{
		c=1;
		int a=m;
		for(int j=i-1;j>=1;j--)
		{
			if(a-i+j>=0)
			{
				c++;
				a=a-i+j;
			}
			else
			{
				continue;
			}
		}
		v=max(v,c);
	}
	cout<<v;
	return 0;
}
