#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[500005],m,t,l,r,ans=1,sum,s;
bool A=true;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i) A=false;
	}
	if(A)
	{
		while(s<=m)
		{
			t++;
			s+=t;
		}
		cout<<min(t,n);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			sum+=(a[i]-a[j]);
			s++;
			if(sum>m) break;
		}
		ans=max(ans,s-1);
		//cout<<s-1<<' ';
	}
	cout<<ans;
	return 0;
}//实在不行搞MO吧 

