#include<bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("card.in ","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,num=0;
	int a[n+1];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=a[i-1])
		{
			num++;
		} 
	}
	cout<<num;
	return 0;
}
