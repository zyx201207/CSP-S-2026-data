#include <bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,as[500005];
int main()
{
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    cin >>n>>m;
    for (int i=1;i<=n;i++) cin >>as[i];
    sort(as+1,as+n+1);
    for (int i=1;i<=n;i++)
    {
		long long p=m;
		int k=1;
		for (int j=i-1;j>0;j--)
		{
			p=p-as[i]+as[j];
			if (p<0) break;
			k++;
		}
		ans=max(k,ans);
    }
    cout <<ans;
    return 0;
}
