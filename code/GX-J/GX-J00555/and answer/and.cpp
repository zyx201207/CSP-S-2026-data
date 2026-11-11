#include <bits/stdc++.h>
using namespace std;
int main()
{
		freopen("and.in","r",stdin);
		freopen ("and.out","w",stdout);
		int n;
		cin>>n;
		int a[1005];
		int maxn=-1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n ;i++)
		{
				if((a[i]<<a[i+1])>maxn)maxn=a[i];
		}
		
		cout<<maxn;
		return 0;
}

