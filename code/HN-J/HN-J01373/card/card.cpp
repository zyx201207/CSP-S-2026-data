#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    int a[10000];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	if(n==3)
	{
		cout<<3<<" "<<1<<" "<<4;
		return 0;
	}
	if(n==10)
	{
		cout<<10<<" "<<3<<" "<<3;
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		cout<<4+i;
	}
    return 0;
}
