#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[200050];
	int ma=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>ma)
		{
			ma=a[i];
		}
	}
    cout<<ma;
	return 0;
}