#include<bits/stdc++.h>
#define N 4005
using namespace std;
namespace shan{
	typedef long long ll;
	int C,T,n,k;
	vector<int>to[N];
	int ml,fat[N];
	void pre(int x,int prt){
		fat[x]=prt;
		for(auto it:to[x])
			if(it!=prt)pre(it,x);
	}
	int e[N][N],dp[N],cnt[N],all;
	void dfs(int x,int prt){
		dp[x]=1;cnt[x]=0;
		for(auto it:to[x])
			if(it!=prt&&!e[x][it])
				dfs(it,x),dp[x]=max(dp[x],dp[it]+1),cnt[x]+=dp[it]>=ml;
	}
	void dfs2(int x,int prt,int lenf){
		cnt[x]+=lenf>=ml;
		lenf++;
		if(cnt[x]>=2)all++;
		int m1=lenf,m2=1;
		for(auto it:to[x]){
			if(it==prt||e[x][it])continue;
			if(dp[it]+1>m1)m2=m1,m1=dp[it]+1;
			else if(dp[it]+1>m2)m2=dp[it]+1;
		}
		for(auto it:to[x])
			if(it!=prt&&!e[x][it])
				dfs2(it,x,m1==dp[it]+1?m2:m1);
	}
	int gets(int x){
		all=0;dfs(x,0);
		dfs2(x,0,0);
		return max(all,1);
	}
	bool check(int x){
		ml=x;
		if(gets(1)<=k)return 1;
		for(int i=2;i<=n;i++){
			e[i][fat[i]]=e[fat[i]][i]=1;
			if(gets(i)+gets(fat[i])<=k){e[i][fat[i]]=e[fat[i]][i]=0;return 1;}
			e[i][fat[i]]=e[fat[i]][i]=0;
		}
		return 0;
	}
    signed main(){
		cin>>C>>T;
		while(T--){
			cin>>n>>k;
			for(int i=1;i<=n;i++)to[i].clear();
			for(int i=1;i<n;i++){
				int x,y;cin>>x>>y;
				to[x].push_back(y);
				to[y].push_back(x);
			}
			if(k==n){cout<<0<<'\n';continue;}
			pre(1,0);
			int l=1,r=n;
			while(l<r){
				int mid=(l+r)>>1;
				if(check(mid))r=mid;
				else l=mid+1;
			}
			cout<<l<<'\n';
		}
		return 0;
	}
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    shan::main();
    return 0;
}
/*
g++ hub.cpp -o hub.exe -Wall -Wextra -static -std=c++14 -O2 
./hub.exe

0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/