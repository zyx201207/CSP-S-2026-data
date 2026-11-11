#include<bits/stdc++.h>
using namespace std;
long long da=2147483647,ans,second,beg,n,m,a[200020]; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
		if(a[i]>=beg)
		{
			second=beg;
			beg=a[i];
		}
		else if(a[i]>=second)
		{
			second=a[i];
		}
	}
	if(m==1)
	{
		cout<<beg;
		return 0; 
	}
	else
	{
		cout<<second;
	}
	return 0;
}
