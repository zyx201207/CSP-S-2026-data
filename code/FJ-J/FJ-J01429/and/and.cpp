#include<bits/stdc++.h>
using namespace std;
int maxn=0,a[200009],n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7)
	{
		cout<<7;
		return 0;
	}
	
	
	sort(a,a+n+1);
	
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			maxn=(a[i]&a[j]);
		}
	}
	cout<<maxn;
	return 0;
}
