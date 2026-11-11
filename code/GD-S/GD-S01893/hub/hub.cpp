#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,k,l,r,mxa[maxn],mxb[maxn],ans=1e9,ta[maxn],tb[maxn],tia[maxn],tib[maxn];
vector<int> v[maxn];
void change(int x,int val){
	if(val>mxa[x]) mxb[x]=mxa[x],mxa[x]=val;
	else if(val>mxb[x]) mxb[x]=val;
}
void dfs(int x,int rt){
	mxa[x]=mxb[x]=0;
	for(int i:v[x]){
		if(i==rt) continue;
		dfs(i,x);
		change(x,mxa[i]+1);
		change(x,mxb[i]+1);
	}
}
void solve(int x,int rt){
	ans=min(ans,max(mxb[x],mxa[x]/2));
	for(int i:v[x]){
		if(i==rt) continue;
		ta[x]=mxa[x],tb[x]=mxb[x],tia[x]=mxa[i],tib[x]=mxb[i];
		mxa[x]=mxb[x]=0;
		for(int j:v[x]){
			if(i==j) continue;
			change(x,mxa[j]);
			change(x,mxb[j]);
		}
		change(i,mxa[x]+1);
		change(i,mxb[x]+1);
		solve(i,x);
		mxa[x]=ta[x],mxb[x]=tb[x],mxa[i]=tia[x],mxb[i]=tib[x];
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		ans=1e9;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			cin>>l>>r;
			v[l].push_back(r);
			v[r].push_back(l);
		}
		dfs(1,0);
		solve(1,0);
		cout<<ans<<"\n";
	}
	return 0;
} 
