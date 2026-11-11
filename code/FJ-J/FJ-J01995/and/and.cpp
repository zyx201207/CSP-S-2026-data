#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],imax=0,s[N],l,mm;
bool pd[N];
void js(int op)
{
	l=(l&a[op]);
}
void dfs(int x,int sum)
{
	if(x+m-sum>n)return;
	if(sum==m)
	{
		l=(a[s[1]]&a[s[2]]);
		for(int i=3;i<=m;i++)
		{
			js(s[i]);
		}
		imax=max(imax,l);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!pd[i]&&i>x&&a[i]!=0)
		{
			pd[i]=1;
			sum+=1;
			s[sum]=i;
			dfs(i,sum);
			s[sum]=0;
			sum-=1;
			pd[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mm=max(mm,a[i]);
	}
	dfs(0,0);
	if(m==1)
	{
		cout<<mm;
		exit(0);
	}
	cout<<imax;
	return 0;
}
