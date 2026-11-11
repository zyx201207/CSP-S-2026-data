#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005];
void solve(int now)
{
	vector<int>f(200005,-1);
	vector<int>pai;
	for(int i=now;i<=n;i++)
	{
		if(f[a[i]]!=-1)
		{
			for(int j=f[a[i]];j<pai.size();)
			{
				f[pai[j]]=-1;
				pai.erase(pai.begin()+j);
			}
			pai.push_back(a[i]);
			f[a[i]]=pai.size()-1;
		}else{
			f[a[i]]=pai.size();
			pai.push_back(a[i]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		b[i]+=(f[i]==-1?0:1);
	}
}
int main ()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		solve(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}

