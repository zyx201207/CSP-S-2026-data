#include<bits/stdc++.h>
using namespace std;
int n,c,t,k,x,y,l,r,m,d,e,f[1000006],g,h;
vector<int> a[1000006];
bool b[1000006],bb[1000006];
queue<int> q;
void dfs(int x,int y){
	if(x>k){
		g=0;
		for(int i=1;i<=n;i++){
			f[i]=2147483647;
			bb[i]=0;
			if(b[i]){
				q.push(i);
				bb[i]=1;
				f[i]=0;
			}
		}
		while(!q.empty()){
			e=q.front();
			q.pop();
			for(int i=0;i<a[e].size();i++){
				if(!bb[a[e][i]]){
					f[a[e][i]]=min(f[a[e][i]],f[e]+1);
					bb[a[e][i]]=1;
					q.push(a[e][i]);
				}
			}
			g=max(g,f[e]);
		}
		h=min(h,g);
		return;
	}
	for(int i=y;i<=n;i++){
		b[i]=1;
		dfs(x+1,i+1);
		b[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		if(k==n){
			cout<<0<<endl;
			continue;
		}
		h=2147483647;
		dfs(1,1);
		cout<<h<<endl;
	}
	return 0;
}
