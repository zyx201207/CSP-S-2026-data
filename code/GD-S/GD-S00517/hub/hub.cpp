#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,x,y,dep[1000005],cnt,id,hh[5],len,ans,ll;
bool flag;
vector<int>v[1000005];
struct o{
	int x,dep;
}pp[1000005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >qe;
void dfs1(int x,int fa){
	for(int y:v[x]){
		if(y==fa)continue;
		dep[y]=dep[x]+1;
		dfs1(x,y);
	}
	if(dep[x]>cnt){
		cnt=dep[x];
		id=x;
	}
}
void dfs2(int x,int id,int fa){
	for(int y:v[x]){
		if(y==fa)continue;
		if(flag){
			if(cnt%2==0&&(dep[x]==cnt/2||dep[x]==cnt/2+1)||cnt%2==1&&dep[x]==cnt/2+1)hh[++len]=x;
			return;
		}
		dfs2(y,id,x);
	}
	if(x==id){
		flag=1;
		if(cnt%2==0&&(dep[x]==cnt/2||dep[x]==cnt/2+1)||cnt%2==1&&dep[x]==cnt/2+1)hh[++len]=x;
		return;
	}
}
void dfs3(int x,int fa){
	bool flag=0;
	for(int y:v[x]){
		if(y==fa)continue;
		flag=1;
		dep[y]=dep[x]+1;
		dfs3(y,x);
	}
	if(!flag){
		pp[++ll]={x,dep[x]};
	}
}
bool cmp(o x,o y){
	return x.dep>y.dep;
}
bool check(int mid){
	for(int i=1;i<=ll;i++){
		if(pp[i].dep<d)
	}
	
}
void sol(int xx){
	ll=0;
	dep[xx]=0;
	dfs3(xx,-1);
	sort(pp+1,pp+1+ll,cmp);
	int l=0,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	ans=min(ans,l);
}
int main(){
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		ans=1e9;
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++)cin>>x>>y,v[x].push_back(y),v[y].push_back(x);
		dep[1]=1;
		cnt=0;dfs1(1,-1);
		cnt=0;
		int id2=id;dep[id]=1;
		dfs1(id,-1);
		flag=0;len=0;
		dfs2(id2,id,-1);
		for(int i=1;i<=len;i++)sol(hh[i]);
		cout<<ans<<endl;
	}
	return 0;
}
