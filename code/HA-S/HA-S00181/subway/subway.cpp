#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005]; 
vector<pair<int,long long> > su[500005];
long long fd[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<=500;i++){
		for(int j=0;j<=500;j++){
			fd[i][j]=200000000000000000;
			if(i==j){
				fd[i][j]=0;
			}
		}
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int kk,xx,yy;
	for(int i=1;i<=n;i++){
		cin>>kk;
		for(int j=1;j<=kk;j++){
			cin>>xx>>yy;
			su[xx].push_back(make_pair(i,yy));
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<su[i].size();j++){
			for(int k=j+1;k<su[i].size();k++){
				xx=su[i][j].first,yy=su[i][k].first;
				fd[xx][yy]=min(fd[xx][yy],su[i][j].second+su[i][k].second);
				fd[yy][xx]=min(fd[yy][xx],su[i][j].second+su[i][k].second);
				//cout<<i<<' '<<su[i][j].first<<' '<<su[i][k].first<<"   "<<fd[xx][yy]<<"\n";
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<j;k++){
				fd[j][k]=min(fd[j][k],fd[i][j]+fd[i][k]);
				fd[k][j]=min(fd[k][j],fd[i][j]+fd[i][k]);
			}
		}
	}/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<fd[i][j]<<' ';
		}
		cout<<"\n";
	}*/
	long long ans=200000000000000000;
	while(q--){
		cin>>xx>>yy;
		ans=200000000000000000;
		for(auto i:su[xx]){
			for(auto j:su[yy]){
				ans=min(fd[i.first][j.first]+i.second+j.second+w[xx]+w[yy],ans);
			}
		}
		cout<<ans<<"\n";
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


0 3 3 8 2
1 1 1
2 1 7 2 3
2 1 9 3 1
2 2 1 3 1


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
