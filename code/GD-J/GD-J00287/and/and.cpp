#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],sum;
void solve1()
{
	int ans=a[1];
	for(int i=2;i<=n;i++) ans&=a[i];
	cout<<ans;
}
void solve2()
{
	int ans=0;
	for(int i=0;i<(1<<n);i++)
	{
		int sum=-114514,cnt=0;;
		for(int j=1;j<=n;j++)
		{
			if(i&(1<<(j-1))) 
			{
				cnt++;
				if(sum==-114514) sum=a[j];
				else sum&=a[j]; 
			}
		}
		if(cnt==m) ans=max(ans,sum);
	}
	cout<<ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==m) solve1();
	else if(n<=20) solve2();
	return 0;
}

