#include<bits/stdc++.h>
using namespace std;
int g,n,m,d,q;
long long w[500005];
vector<long long> a[1010],t[1010],l[1000005];
int k[1010];
int r,c;
long long ans=1e18;
int vis[500010];
int xxx[510],yyy[510];
int z;
void dfs(int x,int y,long long cnt,int num,int h){
//	cout<<x<<' '<<cnt<<endl;
	if(x==y){
		cnt+=t[num][h];
		ans=min(ans,cnt);
		return ;
	}
	if(cnt>=ans){
		return ;
	}
	for(int i=0;i<l[x].size();i++){
		int u=l[x][i],v;
		bool flag=0;
		for(int j=0;j<a[u].size();j++){
			if(a[u][j]==x){
				flag=1;
				continue;
			}
			if(flag==0) continue;
			v=a[u][j];
			
			if(vis[v]==0){
				vis[v]=1;
				if(num==u){
					dfs(v,y,cnt,num,j);
				}
				else{
					if(num!=-1&&h!=-1){
						dfs(v,y,cnt+t[num][h]+t[u][j-1],u,j);
					}
					else{
						dfs(v,y,cnt+t[u][j-1],u,j);
					}
				}
				vis[v]=0;
			}
			break;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>g>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		z++;
		cin>>k[z];
		for(int j=1;j<=k[i];j++){
			cin>>xxx[j]>>yyy[j];
			a[z].push_back(xxx[j]);
			t[z].push_back(yyy[j]);
			l[xxx[j]].push_back(z);
		}
		z++;
		k[z]=k[z-1];
		for(int j=k[z];j>=1;j--){
			a[z].push_back(xxx[j]);
			t[z].push_back(yyy[j]);
			l[xxx[j]].push_back(z);
		}
	}
	while(q--){
		cin>>r>>c;
		for(int i=0;i<=m+3;i++){
			vis[i]=0;
		}
		ans=1e18;
		vis[r]=1;
		dfs(r,c,0,-1,-1);
		ans+=w[r]+w[c];
		cout<<ans<<endl;
	}
	return 0;
}
