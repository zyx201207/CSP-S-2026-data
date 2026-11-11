#include<bits/stdc++.h>
using namespace std;
int n,q,w,a[200005];
int main()
{
	freopen("and.in ","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q=max(max(q,a[i]));
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=q)w=max(w,a[i]);
	}
	cout<<w;
}
