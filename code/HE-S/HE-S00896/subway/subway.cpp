#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e8
int const MAXN = 1e3+10;
ll c,n,m,d,q,k;
ll zs[MAXN];
ll tu[MAXN][MAXN],dtu[MAXN][MAXN],minn=1e8+10;//iœﬂ,jµ„ 
void dfs(ll x,ll y,ll z,ll op)
{
	if(x == y && op==1){minn = min(minn,z);}
	cout <<"/ "<<x << " " << op<<" ? "<< y << " " << z<<endl;
	if(op==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(tu[i][dtu[i][x]]!=0)
			{
				z+=tu[i][dtu[i][x]];
				tu[i][dtu[i][x]] = 0;
				cout <<" "<<x <<" -> " << i <<" "<< op<<endl;
				dfs(i,y,z,0);
			}
		}
	}
	else
	{
		for(int i=1;i<=20;i++)
		{
			if(tu[x][dtu[x][i]]!=0)
			{
				z+=tu[x][dtu[x][i]];
				tu[x][dtu[x][i]] = 0;
				dfs(dtu[x][i],y,z,1);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> zs[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			ll x,y;
			cin >> x >> y;
			dtu[i][j] = x;
			tu[i][dtu[i][j]] = y;
		}
	}
	for(int i=1;i<=q;i++)
	{
		ll x,y;
		cin >> x >> y; 
		dfs(x,y,0,1);
		cout << minn + zs[x] + zs[y] << endl;
	}
	return 0;
}
