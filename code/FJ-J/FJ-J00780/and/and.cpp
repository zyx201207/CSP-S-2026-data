#include <bits/stdc++.h>
using namespace std;
const long long N=5e5;
long long a[N];
long long n,m,cnt=1;
bool flag=0;
long long dfs(int x,int k)
{
	if(k==0)return x;
	if(cnt>n)return x;
	cnt++;
	long long sum1=dfs(x,k);
	cnt--;
	if(flag==0)
	{
		x=(x^a[cnt]);
		flag=1;
	}
	else x=(x&a[cnt]);
	cnt++;
	long long sum2=dfs(x,k-1);
	return max(sum1,sum2);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	cout<<dfs(0,m);
	return 0;
}

