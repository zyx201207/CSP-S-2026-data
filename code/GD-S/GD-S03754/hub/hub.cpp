#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
vector<int>g[1000007];
bool nb(int u,int fa,int len,int s,int cnt,int m){
	if(len>m){
		if(cnt==2){
			s++;
			if(s>k)return false;
		}else{
			if(cnt==0){
				cnt++;
				s++;
				len=0;
			}else{
				if(nb(u,fa,len,s,cnt+1,m)||nb(u,fa,len-1,s+1,cnt,m))return true;
				return false;
			}
		}
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa)continue;
		if(!nb(v,u,len+1,s,cnt,m))return false;
	}
	return true;
}
bool check(int m){
	if(nb(1,0,0,0,0,m))return true;
	return false;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n==k){
		cout<<0<<endl;
		return;
	}
	int l=1,r=1e8;
	while(r-l>1){
		int m=(l+r)/2;
		if(check(m))r=m;
		else l=m;
	}
	cout<<r<<endl;
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
