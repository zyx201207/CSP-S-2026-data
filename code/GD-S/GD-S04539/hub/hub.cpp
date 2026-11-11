#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int c,T,n,k,dst[N];
bool bu[N];
vector<int> m[N];
void ddfs(int it,int step,int fa) {
	dst[it]=min(dst[it],step);
	for(int i:m[it])
		if(i!=fa) ddfs(i,step+1,it);
}
void dfs(int it,int build) {
	if(it>n&&build==k) {
		for(int i=1;i<=n;i++)
			if(bu[i]) ddfs(i,0,-1);
		return;
	}
	if(it>n||build>k) return;
	bu[it]=true;
	dfs(it+1,build+1);
	bu[it]=false;
	dfs(it+1,build);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>T;
	while(T--) {
		cin>>n>>k;
		int ans=0x7fffffff;
		for(int i=1;i<=n;i++) m[i].clear(),bu[i]=false,dst[i]=0x7fffffff;
		for(int i=1,a,b;i<n;i++) {
			cin>>a>>b;
			m[a].push_back(b);
			m[b].push_back(a);
		}
		dfs(1,0);
		for(int i=1;i<=n;i++) ans=min(ans,dst[i]);
		cout<<n/k<<endl;
	}
	return 0;
}
