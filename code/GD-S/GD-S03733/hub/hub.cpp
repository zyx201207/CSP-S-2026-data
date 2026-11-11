#include <bits/stdc++.h>
using namespace std;
const int N=1000010;
int c,T,n,k,rt,f[N],cnt=0,ld=0;
vector<int> ed[N];
void dfs(int x,int fa,int len){
	int ch=0;
	f[x]=0;
	for(int v:ed[x]){
		if(v==fa) continue;
		ch++;
		dfs(v,x,len);
		f[x]=max(f[v]+1,f[x]);
	}
	if(f[x]>=len){
		cnt++;
		if(ch==1){
			if(f[x]!=len) ld++;
			else ld=0;
		}else ld=0;
	}
}
bool check(int x){
	int d=n;
//	cout<<x<<"\n";
	for(int i=1;i<=n;i++){
		for(int v:ed[i]){
			int tmp=0;
			ld=0,cnt=0;
			dfs(i,v,x);
			if(f[i]<x) cnt++,ld=0;
			tmp+=ld;ld=0;
//			cout<<cnt<<"\n";
			dfs(v,i,x);
			if(f[v]<x) cnt++,ld=0;
			tmp+=ld;
			cnt-=tmp;
			if(tmp>x*2) d=min(d,cnt+tmp-x*2);
			else d=min(d,cnt); 
//			cout<<i<<" "<<v<<' '<<f[v]<<" "<<cnt<<' '<<tmp<<' '<<d<<'\n';
		}
	}
	return d<=k; 
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) ed[i].clear();
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			ed[x].emplace_back(y);
			ed[y].emplace_back(x);
		}
		if(n<=2){cout<<"0\n";continue;}
		for(int i=1;i<=n;i++) if(ed[i].size()>=2) rt=i;
		int l=0,r=n+1;
		while(l+1!=r){
			int mid=(l+r)>>1;
			if(check(mid)) r=mid;
			else l=mid;
		}
		cout<<r<<'\n';
	}
	return 0;
}

