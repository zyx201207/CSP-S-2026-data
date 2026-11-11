#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,num=INT_MAX;
int w[500005];
vector <int> w2[500005];
int vis[500005];
struct node{
	int id;
	int t;
};
int a[505][500005];

void dfs(int nx,int st,int ed,int cnt){
	if(cnt>=num)return;
	if(nx==ed){
		num=min(num,cnt);
		return;
	}
	for(int i=0;i<w2[nx].size();i++){
		if(vis[w2[nx][i]])continue;
		for(int j=1;j<=n;j++){
			if(!a[j][nx])continue;
			vis[w2[nx][i]]=1;
			dfs(w2[nx][i],st,ed,cnt+a[1][w2[nx][i]]);
			vis[w2[nx][i]]=0;
		}		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=2*k;j++){
			int x,t;
			cin>>x>>t;
			a[i][x]=t;
			//a[i].push_pack({x,t});
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				if(j==l)continue;
				w2[j].push_back(l);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		num=0;
		dfs(x,x,y,0);
		num+=w[x]+w[y];
		for(int j=x;j<y;j++){
			for(int k=1;k<=n;k++){
				if(!a[k][j])continue;
				num+=a[k][j];
			}	
		}
		cout<<num<<endl;
	}
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
