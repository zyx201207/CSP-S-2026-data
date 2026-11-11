#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,a[N],m,l=1,r=2,pre[N],ans=1,f,s;
int main()
{
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
	}
	while(l<r&&r<=n)
	{
		if(a[r]*(r-l)-(pre[r-1]-pre[l-1])<=m)
		{
			s=r-l+1;
			ans=max(ans,s);
			r++;
		}
		else l++; 
    }
	cout<<ans;
}
/*
5 8
-3 -1 2 2 7
*/
