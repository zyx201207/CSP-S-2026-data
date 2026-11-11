#include<bits/stdc++.h>
using namespace std;
int n,m,arr[200005],ans;
int search(int now,int x,int area)
{
	if(x==0)
	{
		return area;
	}
	int id=now+1;
	for(int i=now+2;i<=n;i++)
	{
		if(area & arr[i] > area & arr[id])
		{
			id=i;
		}
	}
	search(now+1,x-1,area & arr[id]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,search(i,m-1,arr[i]));
	}
	cout<<ans;
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}

