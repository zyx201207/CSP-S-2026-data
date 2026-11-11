#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define int long long
using namespace std;

int c,n,m,d,q,w[500005];
int k[505];
vector<int> a[505],t[505];
int ans,l,r;
bool vis[500005];

void dfs(int now,int all,int line,int nowid){
	//cout<<now<<" "<<all<<" "<<line<<" "<<nowid<<endl;
	if(now==r){
		all+=t[line][nowid];
		ans=min(ans,all);
		return;
	}
	if(vis[now]) return;
	vis[now]=true;
	
	int tmp=all;
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++){
			if(a[i][j]==now){
				if(j<a[i].size()-1){
					int newtime=all;
					if(now==l){
						newtime+=t[i][j];
					}
					if(i!=line && line!=0){
						newtime=newtime+t[line][nowid]+t[i][j];
					}
					dfs(a[i][j+1],newtime,i,j+1);
				}
				
				if(j>0){
					int newtime=all;
					if(now==l){
						newtime+=t[i][j];
					}
					if(i!=line && line!=0){
						newtime=newtime+t[line][nowid]+t[i][j];
					}
					dfs(a[i][j-1],newtime,i,j-1);
				}
			}
		}
	}
	vis[now]=false;
	return;
}

vector<int> g[500005];


signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int tmp1,tmp2;
			cin>>tmp1>>tmp2;
			a[i].push_back(tmp1);
			t[i].push_back(tmp2);
		}
	}
	
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		ans=1e9;		
		dfs(l,0,0,0);
		ans=ans+w[l]+w[r];
		cout<<ans<<endl;
	}
	return 0;
}



 


 





