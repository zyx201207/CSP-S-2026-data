#include<bits/stdc++.h>
using namespace std;
long long a[200010],maxn=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	maxn=max(a[i],maxn);
    	if(i!=1)
    	{
    		a[1]&=a[i];
		}
	}
	if(m==n)
	{
		cout<<a[1];
		return 0;
	}
	cout<<maxn;
    return 0;
}