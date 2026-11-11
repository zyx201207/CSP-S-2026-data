#include <bits/stdc++.h>
using namespace std; 
const long long N=5e5+1000;
long long n,m;
long long a[N],b[N];
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
    for(int i=1;i<=m;i++)
    {
    	if(i==a[n])cout<<n<<" ";
    	else cout<<b[i]<<" ";
	}
	return 0;
}

