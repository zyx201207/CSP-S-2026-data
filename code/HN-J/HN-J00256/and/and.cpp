#include<bits/stdc++.h>
using namespace std;
int n,a[200002];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=0;i--)
	{
		if(a[i]==a[i])
		{
			cout<<a[i];
			break;
		}
	}
	return 0;
 } 
