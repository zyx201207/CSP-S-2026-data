#include<bits/stdc++.h> 
using namespace std;
int a[2000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool bj=0;
	int mx=-1000000000;
	if(m==1)
	{
		bj=true;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(bj)
		{
			mx=max(a[i],mx);
		}
	}
	if(bj)
	{
		cout<<mx;
	}	
    return 0;
}

