#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int ans;
bool check(int x)
{
	int y=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]+m<x) continue;
		if(a[i]>=x) break;
		y=y+x-a[i];
	} 
	return y<=m;
}
int find()
{
	int l=a[1]-1,r=a[n]+m+1;
	while(l+1<r)
	{
		int mid=l+r>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	return l;
}
signed main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int x=find();
	for(int i=1;i<=n;i++)
	{
		if(a[i]>x) break;
		ans++;
	}
	cout<<ans;
	return 0;	
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/

