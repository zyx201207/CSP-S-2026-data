#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9+7;
const int N=1e6+7;
vector<int>edge[N];
int n,k;
void clear(){
	for(int i=1;i<=n;i++){
		edge[i].clear();
		edge[i].shrink_to_fit();
	}
}
bool tag[N];
bool tmp[N];
void cover1(int u){
	tmp[u]=false;
	for(auto v:edge[u]){
		if(tmp[v]==false) continue;
		cover1(v);
	}
	return;
}
int find1(int u,int f){
	if(tag[u]==true) return 0;
	int res=0;
	for(auto v:edge[u]){
		if(v==f) continue;
		res=max(res,find1(v,u));
	}
	return res+1;
}
int check1(int state){
	for(int i=0;i<n;i++) tag[i+1]=((state>>i)&1);
	for(int i=1;i<=n;i++) tmp[i]=tag[i];
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(tmp[i]==true){
			cover1(i);cnt++;
		}
	}
	if(cnt!=2) return inf;
	int res=0;
	for(int i=1;i<=n;i++){
		res=max(res,find1(i,-1));
	}
	return res;
}
int solve1(){
	int res=inf;
	for(int i=0;i<(1<<n);i++){
		int cnt=0,tmp=i;
		while(tmp){
			tmp=tmp-(tmp&(-tmp));
			cnt++;
		}
		if(cnt!=k) continue;
		res=min(res,check1(i));
	}
	return res;
}
//---------------------------
int c,T;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		clear();
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		int res=0;
		if(0<=c&&c<=3) res=solve1();
		cout<<res<<"\n";
	}
	return 0;
}
