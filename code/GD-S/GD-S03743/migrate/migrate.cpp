#include <bits/stdc++.h>
#define ll long long
#define N 2000006
using namespace std;
ll pos[N],d;
int Min[N];
int Cnt[N],to[N];
void dfs(int x,int cnt){
	if(Min[x]<cnt)
		return ;
	if(Min[x]==cnt)
		Cnt[x]++;
	else
		Cnt[x]=1,Min[x]=cnt;
	if(to[x]==-1){
		int z=x;
		for(;pos[x]+d>=pos[z];z++);
		to[x]=--z;
	}
	for(int z=to[x];z>x;z--)
		dfs(z,cnt+1);
}
void sol(){
	int n;
	cin>>n>>d;
	pos[n]=LLONG_MAX;
	for(int x=0;x<n;x++)
		cin>>pos[x];
	int ans=0;
	memset(to,-1,sizeof(int)*(n+2));
	for(int x=0;x<n;x++){
		memset(Min,0x3f,sizeof(int)*(n+2));
		memset(Cnt,0,sizeof(int)*(n+2));
		dfs(x,0);
		for(int z=x+1;z<n;z++)
			if(Cnt[z]==2)
				ans++;
	}
	cout<<ans<<'\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>T>>T;
	while(T--)
		sol();
}

