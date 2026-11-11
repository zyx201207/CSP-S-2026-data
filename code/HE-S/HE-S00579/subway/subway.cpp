#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[100005],k[555],t[550][100005],ans,a[550][100050];
vector<int> e[100050]; 
void dfs(int now,int xian,int res,int end){
	if(now==end){
		int p=0;
		for(int i=1;i<=k[xian];i++){
			if(a[xian][i]==now){
				p=i;
				break;
			}
		}
		ans=min(ans,res+t[xian][p]+w[now]);
		return ;
	}
	for(int i=1;i<=k[xian];i++){
		if(a[xian][i]==now){
			while(i+1<=k[xian]){
				i++;
				dfs(a[xian][i],xian,res,end);
			}
		}
	}
	//cout<<now<<endl;
	for(int i=0;i<(int)e[now].size();i++){
		int nxt=e[now][i];
		if(nxt==xian)continue;
		for(int j=1;j<=k[nxt];j++){
			if(a[nxt][j]==now){
				int p=j;
				while(j+1<=k[nxt]){
					j++;
					//cout<<now<<" "<<xian<<" "<<a[nxt][j]<<" "<<nxt<<" "<<res+t[xian][now]+t[nxt][p]<<endl;
					dfs(a[nxt][j],nxt,res+t[xian][now]+t[nxt][p],end);
				}
			}
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
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			e[a[i][j]].push_back(i);
			cin>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=INT_MAX;
		for(int i=0;i<(int)e[x].size();i++){
			dfs(x,e[x][i],t[e[x][i]][x],y);
		}
		cout<<ans+w[x]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
