#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k,siz[N];
vector<int> e[N];
vector<int> lf;
bool vis[N];
bool check(int mid){
	memset(vis,0,sizeof(vis));
	queue<pair<int,int>> q;
	for(int i=0;i<lf.size();i++){
		int u=lf[i];
		vis[u]=true;
		q.push({u,1});
	}
	while(!q.empty()){
		int u=q.front().first,w=q.front().second;
		q.pop();
		if(w>=mid) continue;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i];
			if(vis[v]==true) continue;
			q.push({v,w+1});
			vis[v]=true;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			cnt++;
		}
	}
	if(cnt<=k) return true;
	else return false;
}
bool lian(){
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(e[i].size()==1){
			cnt1++;
		}
		if(e[i].size()==2){
			cnt2++;
		}
	}
	if(cnt1==2&&cnt2==n-2){
		return true;
	}else{
		return false;
	}
}
void solve(int TT){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		if(!e[i].empty()){
			e[i].clear();
		}
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(lian()==true){
		n=(n+1)/2;
		k/=2;
		cout<<(n-k+1)/2<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(e[i].size()==1){
			lf.push_back(i);
		}
	}
	if(n==k){
		cout<<0<<"\n";
		return;
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)==true){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TT,T=1;
	cin>>TT>>T;
	while(T--){
		solve(TT);
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
