#include<bits/stdc++.h>
using namespace std;
struct node{
	int zh,ti;
};
int p2,t;
long long c,n,m,d,q;
long long ans;
int w[500005],k[505];
vector<int  > a[2000005];
vector<int  > b[505];//b表轨道->点，a表点->轨道 
int e[5005][505];
bool f[505];
vector<int> p[505];
queue<int> p1;
long long bfs(queue<int>& p1,int z){
	int g[505];
	g[p1.front()]=1; 
	f[p1.front()]=1;
	while(!p1.empty()){
		for(int i=0;i<b[p1.front()].size();i++){
			if(b[p1.front()][i]==z)
			return g[p1.front()];
		}
		for(int i=0;i<p[p1.front()].size();i++){
			if(!f[p[p1.front()][i]])
			p1.push(p[p1.front()][i]);
			f[p1.front()]=1;
			g[p[p1.front()][i]]=g[p1.front()]+1;
		}
		p1.pop();
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i_=1;i_<=n;i_++){	
		cin>>k[i_];
		for(int i=1;i<=k[i];i++){
			 p2,t;
			cin>>p2>>t;
			a[p2].push_back(i_);
			b[i_].push_back(p2);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			int x=b[i][j];
			for(int k=0;k<a[x].size();k++){
				int y=a[x][k];
				p[i].push_back(y);
			}
		}
	}
	for(int i_=1;i_<=q;i_++){
		int l,r;
		cin>>l>>r;
			p1.push(a[l][0]);
			cout<<bfs(p1,r)*t*2+w[l]+w[r];
			while(!p1.empty())
			p1.pop();
	}
	return 0;
}
