#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
    	if(a[i]<a[i+1])
		{
			max=a[i+1];
		}
		else
		{
			max=a[i];
		}
		if(m==1)
		{
			cout<<max;
			return 0;
		}
	}
	return 0;
}
