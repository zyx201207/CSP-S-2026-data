#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,maxx=-1;
long long s[N];
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	    cin>>s[i];
	}
	sort(s+1,s+1+n);
	cout<<s[n-m+1];
	return 0;
}
