#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ma,ans;
bool w[200005][35];
void f(int x,int i)
{
	int t=0;
	while(x) w[i][++t]=x%2,x/=2;
	ma=max(ma,t);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],f(a[i],i);
	for(int i=ma;i>0;i--)
	{
		int cnt=0;
		vector<int>e;
		for(int j=1;j<=n;j++)
		{
			if(w[j][i]) cnt++,e.push_back(a[j]);
		}
		if(cnt>=m)
		{
			sort(e.begin(),e.end(),greater<int>());
			cout<<e[m-1];return 0;
		}
	}
	cout<<0;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
