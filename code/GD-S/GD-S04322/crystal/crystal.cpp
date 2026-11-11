#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

const int N=5e5;

int n; long long m;
long long a[N+1];

long long c[N+1];
int ans;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) c[i]=a[i]-a[i-1];
	
	int l=1; long long sum=0;
	for(int r=1;r<=n;r++)
	{
		sum+=c[r]*(r-l);
		while(l<=r&&sum>m) sum-=a[r]-a[l++];
		ans=max(ans,r-l+1);
	}
	
	cout<<ans;
	
	return 0;
}

