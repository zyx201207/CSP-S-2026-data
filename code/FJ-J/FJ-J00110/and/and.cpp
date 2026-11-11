#include<bits/stdc++.h>
using namespace std;
#define int long long
#define i64 __int128_t
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>;
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
const int mod=1e9+7;
int pows(int a,int b)
{
	int ret=1;
	while(b){
		if(b&1)ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}

void Dddd()
{
	int n,m;
	cin>>n>>m;
	vector<int>v(n+1); 
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	int mx=0;
	vector<int>a,st(n+1);	
	auto dfs=[&](auto && dfs,int x,int idx)->void{
		if(x>m){
			int x=v[a[0]];
			for(auto i:a){
				x&=v[i];
			}
			mx=max(mx,x);
			return;
		}
		for(int i=idx;i<=n;i++){
			if(st[i])continue;
			st[i]=1;
			a.push_back(i);
			dfs(dfs,x+1,i+1);
			st[i]=0;
			a.pop_back();
		}
	};
	dfs(dfs,1,1);
	cout<<mx<<endl;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int num=1;
//	cin>>num;
	while(num--)
	{
		Dddd();
	}
	return 0;
}

