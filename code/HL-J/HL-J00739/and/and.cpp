#include<bits/stdc++.h>
using namespace std;
int n,m,w;
long long a[100000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		a[i]&=a[i+1];
		   if(w<a[i])
		   {
		   w=a[i];
	       }	
	}
	cout<<w;
	return 0;
}