#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[100005],b[100005],c[100005];
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
	    cin >> a[i];
		b[a[i]]++;
		c[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
	    if(b[a[i]]!=0)
	    {
	        cout << i << " ";
	       }
	       b[a[i]]--;
	}
	return 0;
}
