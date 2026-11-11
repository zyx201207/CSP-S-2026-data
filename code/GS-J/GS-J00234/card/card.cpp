#include <bits/stdc++.h>
using namespace std;
int n,m,a[5000],ans=0;
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
    }
	cin>>n>>m>>ans;
	for(int i=1;i<=4;i++)
	{
		if(n%a[i]==i)
		{
			ans++;
		}
	}
	cout<<ans<<" ";
    return 0;
}
