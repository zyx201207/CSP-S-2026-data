#include<bits/stdc++.h>
using namespace std;
int c,t,l,n,m,ans,maxxx;
vector<int>a[2000010];
int dfs(int x,int y,int z){
	int maxx=0;
	
	for(int i=0;i<a[x].size();i++){
		if(a[x][i]!=z)maxx=max(maxx,dfs(a[x][i],y+1,x));
	}if(a[x].size()==1)return y;
	return maxx;
}
int main(){
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int pp=1;pp<=t;pp++){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			a[i].clear();
		}
		for(int i=1;i<n;i++){
			int v,u;
			cin>>v>>u;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			if(a[i].size()==1){
				int yy=dfs(a[i][0],0,0);
				maxxx=max(maxxx,yy)+1;
			}
		}cout<<(maxxx-m+3)/4<<endl;
	}
	return 0;
}//0 2 5 2 1 2 2 3 3 4 4 5 10 3 1 2 1 3 2 4 2 5 3 6 3 7 3 8 7 9 9 10
