#include<bits/stdc++.h>
using namespace std;
#define int long long
#define i64 __int128_t 
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using pii = pair<int,int>;
mt19937_64 rng(random_device{}());
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
const int mod=1e9+7;
int pows(int a,int b)
{
	int ret=1;
	while(b){
		if(b&1)ret=ret*a;
		a*=a;
		b>>=1;
	}
	return ret;
}
void Dddd()
{
	int n,m,d,q;
	cin>>n>>m>>d>>q;
	vector<int>t(m+1);
	for(int i=1;i<=m;i++)
	{
		cin>>t[i];		
	}
	vector<pii>li;
	vector<vector<int>>z(m+1,vector<int>(m+1,INF)); 
	for(int l=1;l<=n;l++)
	{
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++)
		{
			int x,w;
			cin>>x>>w;
			li.push_back({x,w});
		}
	}
	int lax=0,law=0;
	for(auto p:li)
	{
		int x=p.first,w=p.second;
		z[lax][x]=min(z[lax][x],w+law);
		z[x][lax]=min(z[x][lax],w+law);
		lax=x,law=w; 
	}
	for(int i=1;i<=m;i++)z[i][i]=0;
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				z[i][j]=min(z[i][j],z[i][k]+z[k][j]);	
			}
		}
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		int sum=t[l]+t[r]+z[l][r];
		cout<<sum<<endl;
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int _,num=1;
	cin>>_;
	while(num--)
	{
		Dddd();	
	} 
	return 0;
}
