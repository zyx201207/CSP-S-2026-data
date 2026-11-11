#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],f[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	m--;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=-1;
	}
    while(m--)
    {
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=n;j>=1;j--)
    		{
    			f[i]=max(f[i],f[j-1]&a[j]);
			}
		}
	}
    cout<<f[n];
	return 0;
}
