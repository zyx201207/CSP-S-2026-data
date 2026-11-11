#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
vector<long long> v[505];
int c,m,n,d,q,a[N],k[505],b[505][N],tim[505][N];
long long s,t,ans=0x3f3f3f,dis[N];
void dfs(long long x,long long cur,long long pos)
{
	if(pos==t)
		ans=min(ans,cur);
	dis[pos]=1;
	long long i;
	for(i=1;i<=k[x];i++)//zhan dian
	{
		if(dis[b[x][i]]==0){
			cur+=tim[x][i];
			for(auto g:v[i]){//xian lu
				dfs(g,cur+tim[g][i],i);}}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	long long i;
	for(i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	long long j;
	for(j=1;j<=n;j++){
		cin>>k[j];
		for(i=1;i<=k[j];i++){
			cin>>b[j][i]>>tim[j][i];
			v[b[j][i]].push_back(j);
		}
	}
	while(q--)
	{
		cin>>s>>t;
		ans=0x3f3f3f;
		memset(dis,0,sizeof(dis));
		for(i=1;i<=n;i++){
			if(b[i][s]!=0){
				dfs(i,tim[i][s],s);}}
		ans=a[t]+a[s];
		cout<<ans<<"\n";
	}
}
/*
 * sdy
Oct31==Dec25?
0 2 5 20 2 
4 1 9 2 5  
3 1 5 2 7 4 6  
3 2 3 3 4 5 7   
1 3
1 2
* i
 */ 
