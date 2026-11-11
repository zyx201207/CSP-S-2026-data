#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
int to,w;
};
int c,n,m,d,q;
int kdt[1001];
int tdt[1001][51001];
vector<node>t[1001];
int ns,s[1001],v[1001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c<=11){
		for(int i=1;i<=m;i++)cin>>kdt[i];
		for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		if(i==j)tdt[i][j]=0;
		else tdt[i][j]=INT_MAX;
		for(int i=1;i<=n;i++){
			cin>>ns;
			for(int k=1;k<=ns;k++){
				cin>>s[k]>>v[k];
				for(int j=k-1;j>=0;j--){
					tdt[s[k]][s[j]]=tdt[s[j]][s[k]]=min(v[k]+v[j],tdt[s[k]][s[j]]);
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=m;k++){
					if(tdt[i][k]+tdt[k][j]<tdt[i][j]){tdt[i][j]=tdt[i][k]+tdt[k][j];}
				}
			}
		}
		int x,y;
		/*
		for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)
		cout<<tdt[i][j]<<" ";
		cout<<'\n';
	}*/
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			cout<<kdt[x]+kdt[y]+tdt[x][y]<<'\n';
		}
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
