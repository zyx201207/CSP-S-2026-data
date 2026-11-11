#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=100000002;

int c,n,m,d,q;
map<pair<int,int>,int> ma; // 邻接矩阵，-1 为无，0 为自己，其它为线路 id 
vector<map<int,int>> st; // 点对于每条线路的换乘时间 

vector<bool> vis;
int solve(int xr,int yr,int at) {
	if(xr==yr) return st[yr][at];
	vis[xr]=true;
	int mini=INF;int ans;
	for(int i=1;i<=m;i++) {
		auto it=ma.find(make_pair(xr,i));
		if(it!=ma.end()) {
		    int temp=ma[make_pair(xr,i)];
		    ans=0;
		    if(!at) {
		    	ans=st[xr][temp];
		    	at=temp;
			}
		    else if(temp!=at) {
		    	ans=st[xr][at]+st[xr][temp];
		    	at=temp;
			}
			if(!vis[i]) {
				ans+=solve(i,yr,at);
			    mini=min(mini,ans);
			}
		}
	} 
	if(mini!=INF) return mini;
	else return ans;
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdin);
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	
	vector<int> w(m+1,0);
	
	// IO
	cin>>c>>n>>m>>d>>q;
	st.resize(m+1);
	int xa,xt,lxa,klen;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
		ma[make_pair(i,i)]=0;
	}
	for(int i=1;i<=n;i++) { // 第 i 条线路 
		cin>>klen;
		lxa=-1;
		for(int ki=1;ki<=klen;ki++) {
			cin>>xa>>xt;
			if(lxa!=-1) {
				ma[make_pair(xa,lxa)]=i;
				ma[make_pair(lxa,xa)]=i;
			}
			st[xa][ki]=xt;
			lxa=xa;
		}
	}
	
	int xr,yr;
	vis.resize(m+1);
	while(q--) {
		cin>>xr>>yr;
		for(int i=1;i<=m;i++) vis[i]=false;
		cout<<w[xr]+w[yr]+solve(xr,yr,0)<<"\n";
	}
	
	return 0;
} 
