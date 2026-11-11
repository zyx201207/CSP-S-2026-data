#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int c,T,n,k,ans;
int flag[N];
int ju[N];
vector <int> v[N];
void c_dfs(int now,int fa){
	for(auto x:v[now]){
		if(x==fa)continue;
		ju[x]=min(ju[x],ju[now]+1);
		c_dfs(x,now);
	}
}
void check(){
	for(int i=1;i<=n;i++)ju[i]=0x7fffffff;
	for(int i=1;i<=n;i++){
		if(flag[i]){
			ju[i]=0;
			c_dfs(i,0);
		}
	}
	int tp=0;
	for(int i=1;i<=n;i++)tp=max(tp,ju[i]);
	ans=min(ans,tp);
}
void dfs(int now,int fa,int lian,int last,int rem){
	if(rem==0){
		check();
	}
	for(auto x:v[now]){
		if(x==fa)continue;
		if(lian<=2){
			if(last==1){
				if(rem>0){
					flag[x]=1;
					dfs(x,now,lian,1,rem-1);
					flag[x]=0;
				}else{
					dfs(x,now,lian,0,rem);
				}
			}
			if(last==0&&lian!=2){
				if(rem>0){
					flag[x]=1;
					dfs(x,now,lian+1,1,rem-1);
					flag[x]=0;
				}else{
					dfs(x,now,lian,0,rem);
				}
			}
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		ans=0xffffffff;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0,0,0,k);
		cout<<ans-1<<'\n';
		for(int i=1;i<=n;i++)v[i].clear();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
