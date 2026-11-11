#include<bits/stdc++.h>
using namespace std;
#define ll long long 
vector<int> q[100001];
ll w[100001];
int k[100001];
int vis[100001];
ll minn=INT_MAX;
int y,c,n,m,d,p;
void dfs(int x,ll cnt,int fz){
//	cout<<x<<' ';
//	if(cnt>minn) return;
	if(x==y){
		minn=min(cnt,minn);
//		cout<<"\n"<<minn;
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			int f=0,fx=0;
			for(int j=0;j<q[i].size();j+=2){
				if(x==q[i][j]){
					f=i;
					fx=q[i][j+1];
				}
			}
			if(f){
				for(int j=0;j<q[i].size();j+=2){
					int xy=q[i][j];
					if(vis[xy]==0&&xy!=x){
						vis[xy]++;
						if(fz!=f){
							dfs(xy,cnt+q[i][j+1]+fx,f);
						}
						else{
							dfs(xy,cnt+q[i][j+1],f);
						}
						vis[xy]--; 
					}
//					cout<<xy<<' ';
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=0;j<k[i]*2;j++){
			int x;
			cin>>x;
			q[i].push_back(x);
		} 
	}
//	cout<<q[3].size()<<"\n";
	for(int i=1;i<=p;i++){
		memset(vis,0,sizeof(vis));
		int x;
		y=0;
		minn=INT_MAX;
		cin>>x>>y;
		vis[x]=1;
		dfs(x,w[x]+w[y],0);
		vis[x]=0;
		cout<<minn<<endl;
	}
	return 0;
} 
