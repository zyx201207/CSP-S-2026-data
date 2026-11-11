#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],b[100010],ans,k,omg=7;
bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
    for(int i=1;i<=m;i++)
    {
    	b[i]=a[i];
	}
	if(m==1)
	{
		ans=b[1];
	}
	if(m==2)
	{
		ans=b[2]&b[1];	
	}
	else
	{
		ans=b[2]&b[1];
		for(int i=3;i<=m;i++)
	    {
			ans=ans&b[i];
	    }
	}
	
	cout<<ans;
	return 0;
}
