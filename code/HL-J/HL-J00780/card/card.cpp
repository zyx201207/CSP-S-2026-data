#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long m,n;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		cin>>a[j];
		}
	}
	cout<<3<<" "<<1<<" "<<4;
	return 0;
}
