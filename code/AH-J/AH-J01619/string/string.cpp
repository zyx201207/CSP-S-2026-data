#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],ans;
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i]>>c[i];
	int j=n;
	for(int i=1; i<=n && j>i; i++)
	{
		while(a[i] && j>i)
		{
			if(c[i]!=c[j])
			{
				if(a[i]>=a[j]) ans+=a[j],a[i]-=a[j],a[j]=0,j--;
				else ans+=a[i],a[j]-=a[i],a[i]=0; 
			}
			else
			{
				if(a[i]>=a[j]) a[i]-=a[j],a[j]=0,j--;
				else a[j]-=a[i],a[i]=0; 
			}
		}
	}
	cout<<ans;
	return 0;
}
