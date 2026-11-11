#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[10000005];
int mp[10005][10005];
int lines[10005][10005];
int g[10000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j){
				mp[i][j]=0;
				continue;
			}
			mp[i][j]=1E6;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>g[i];
		for(int j=1;j<=g[i];j++){
			int num,l;
			cin>>num>>l;
			mp[num][num]+=l;
			lines[i][j]=num;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=g[i];j++){
			for(int k=1;k<=g[i];k++){
				if(lines[i][j]==lines[i][k]){
					continue;
				}
				mp[lines[i][j]][lines[i][k]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j){
				continue;
			}
			for(int k=1;k<=m;k++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]+mp[k][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+mp[x][x]+mp[x][y]+mp[y][y]+w[y]<<endl;
	}
	return 0;
}
