#include<bits/stdc++.h>
using namespace std;
#define int long long
#define i64 __int128_t
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using pii=pair<int,int>;
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
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	vector<int>t,cnt(m+1);
	auto bs=[&](int l,int r,int x)
	{
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if(t[mid]==x) l=mid;
			else r=mid-1;
		}
		return l;
	};
	t.push_back(0);
	for(int p=1;p<=n;p++)
	{
		for(int j=p;j<=n;j++)
		{
			int x=bs(1,t.size(),v[j]);
			if(t[x]==v[j])
			{
				for(int i=x;i<=t.size();i++)
				{
					t.pop_back();
				}
			}
			t.push_back(v[j]);
		}
		for(auto i:t)
		{
			cnt[i]++;
		}
		t.clear();
		t.push_back(0);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";	
	}
	
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
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

