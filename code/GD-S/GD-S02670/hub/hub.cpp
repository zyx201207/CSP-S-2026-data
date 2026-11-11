#include<bits/stdc++.h>
using namespace std;
long long n,m,arr[500005],ans;
void solve()
{
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(i>=3)
		{
			if(arr[i]-arr[i-1] != arr[i-1]-arr[i-2]) f=0;
		}
	}
	//特殊性质A&B 
	if(f)
	{
		int q=arr[2]-arr[1],cnt=0;
		while(cnt<n)
		{
			m-=q;
			cnt++;
		}
		cout<<cnt;
		return;
	}
	//正常 
	sort(arr+1,arr+n+1);
	int i=2,j=1;
	do
	{
		if(m<=0 || arr[i]-arr[j] > m) break;
		if(j==i)
		{
			i++;
			j=1;
		}
		if(arr[i]-arr[j] <= m)
		{
			int f=arr[i]-arr[j];
			arr[j]+=f;
			m-=f;
			
			j++;
			ans++;
		}
	}while(i<=n && i>=1);
	for(int k=i+1;k<=n;k++)
	{
		if(arr[k]!=arr[i]) break;
		ans++;
	}
	cout<<min(ans,n)<<' '<<ans;
	return;
}
int main()
{
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}
