#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> g[10005];
int dep[10005];
int jump[10005],vis[10005];
vector<pair<int,int>> old;
priority_queue<pair<int,int>> q;
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	if (g[x].size()==1&&fa!=0){
		old.push_back({dep[x],x});
	}
	jump[x]=fa;
	for (int i:g[x]){
		if (i==fa)continue;
		dfs(i,x);
	}
}
int n,k;
int go(int x,int D){
	for (int i=1;i<=D;i++){
		if (vis[x]){
			return -1;
		}
		x=jump[x];
	}
	if (vis[x]){
		return -1;
	}
	return x;
}
bool cmp(int aa,int bb){
	return aa>bb;
}
bool check(int dist){
	for (int i=1;i<=n;i++)vis[i]=0;
	for (pair<int,int> i:old){
		q.push(i);
	}
	int cnt=0;
	vector<int> rest;
	while(!q.empty()){
		pair<int,int> t=q.top();
		q.pop();
		int x=go(t.second,dist);
		if (x!=-1&&x!=0){
			if (x!=1){
				q.push({dep[jump[x]],jump[x]});
			}
			vis[x]=1;
			cnt++;
		}
		if (x==0){
			rest.push_back(dep[t.second]);
		}
	}
	if (rest.size()>1){
		sort(rest.begin(),rest.end(),cmp);
		if (rest[0]+rest[1]-2>dist)cnt++;
	}
	return cnt<=k;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>t>>t;
	while(t--){
		cin>>n>>k;
		old.clear();
		for (int i=1;i<=n;i++){
			dep[i]=0;
			vis[i]=0;
			g[i].clear();
			jump[i]=0;
		}
		for (int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		int l=1,r=n;
		while(l<r){
			int mid=l+r>>1;
			if (check(mid)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		cout<<r<<endl;
	}
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
