#include <bits/stdc++.h>
using namespace std;
int n,m,maxn,ans;
int cmp(int a,int s)
{
	return a>s;
}
int a[200010];
void dfs(int ge,int sum,int num)
{
	
	if(ge>n||sum>m) return;
	if(sum==m)
	{
		if(num>ans) ans=num;
		return;
	}
	if(sum==0)
	{
		num=maxn;
	}
	dfs(ge+1,sum+1,(num&a[ge]));
	if(sum==0)
	{
		num=0;
	}
	dfs(ge+1,sum,num);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int sum;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		if(i==1) sum=a[i];
		if(a[i]>maxn) maxn=a[i];
		sum=(sum&a[i]);
    }
    if(m==1||n>2000)
    {
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	dfs(1,0,maxn);
	cout<<ans;
    return 0;
}
