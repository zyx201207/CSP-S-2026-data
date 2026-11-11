#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
vector<int> ls[12000];
int jl[1200][1200];
int xuan[1200];
void f(int x,int fa,int rt){
	for(int i=0;i<ls[x].size();i++){
		int v=ls[x][i];
		if(v==fa) continue;
		jl[rt][v]=jl[rt][x]+1;
		f(v,x,rt);
	}
}
set<int> st;
int ans=1e9;
int ran[12000];
void f3(int x,int fa){
	ran[x]=1;
	for(int i=0;i<ls[x].size();i++){
		int v=ls[x][i];
		if(v==fa || xuan[v]==0) continue;
		ran[v]=1;
		f3(v,x);
	}
}
void f2(int b){
	if(b!=n+1){
		xuan[b]=1;
		f2(b+1);
		xuan[b]=0;
		f2(b+1);
		return;
	}
	st.clear();
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(xuan[i]==1){
			st.insert(i);
			cnt++;
		}
		ran[i]=0;
	}
	if(cnt>m) return;
	cnt=0;
	for(auto t:st){
		if(ran[t]==0){
			f3(t,0);
			cnt++;
		}
	}
	if(cnt>2) return;
	int vis=0;
	for(int i=1;i<=n;i++){
		if(xuan[i]==0){
			int mis=1e9;
			for(auto t:st){
				mis=min(mis,jl[i][t]);
			}
			vis=max(vis,mis);
		}
	}
	ans=min(ans,vis);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			ls[i].clear();
			xuan[i]=0;
			ran[i]=0;
			jl[i][i]=0;
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			ls[x].push_back(y);
			ls[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			f(i,0,i);
		}
		f2(1);
		cout<<ans<<"\n";
	}
}
