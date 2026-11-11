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
	int n,m;
	cin>>n>>m;
	vector<int>v(n+1);
	int ok=1;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];	
	}
	for(int i=3;i<=n;i++){
		if(v[i]-v[i-1]!=v[2]-v[1])ok=0;
	}
	std::sort(v.begin()+1,v.end());
	vector<int>d(n+1);
	for(int i=2;i<=n;i++)
	{
		d[i]=v[i]-v[i-1];
	}
	int mx=-INF;
	if(ok)
	{
		int sum=0,l=1,r=1;
		while(sum<m && r++<=n)
		{
			sum+=d[r]*(r-l+1);
		}
		mx=max(mx,r-l+1);
		cout<<mx<<endl;
		return;
	}
	for(int l=1;l<=n-mx;l++)
	{
		int sum=0,r=l;
		while(sum<m && r++<=n)
		{
			sum+=d[r]*(r-l+1);
		}
		mx=max(mx,r-l+1);
	}
	cout<<mx<<endl;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int num=1;
//	cin>>num;
	while(num--)
	{
		Dddd();	
	} 
	return 0;
}
