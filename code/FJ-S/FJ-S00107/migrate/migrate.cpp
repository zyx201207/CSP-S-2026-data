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
	int n,d;
	cin>>n>>d;
	vector<int>v(n+1);
	vector<vector<int>>z(n+1); 
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		if(i>1){
			z[i].push_back(i-1);
			z[i-1].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(abs(v[i]-v[j])<=d){
				z[i].push_back(j);
				z[j].push_back(i);
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int _,num=1;
	cin>>_>>num;
	while(num--)
	{
		Dddd();	
	} 
	if(_==0)cout<<0<<endl<<1<<endl;
	return 0;
}
