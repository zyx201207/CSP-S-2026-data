#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans,sum;
bool v[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	if(m==n)
	{
		for(int i=2;i<=n;i++)
		  a[i]&=a[i-1];
		cout<<a[n];
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
	    int s=a[i];
		for(int j=i;j<=i+m-1;j++)
		    s&=a[j];
		ans=max(ans,s);
 	}
 	cout<<ans;
	
	return 0;
}
