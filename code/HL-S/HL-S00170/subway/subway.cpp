#include<iostream>
#include<vector>
#include<utility>
long long w[500001],dist[501][501];
std::vector<std::pair<int,long long>>st[500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);std::cout.tie(0);
	int c,n,m,d,p;std::cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		std::cin>>w[i];
	}for(int i=1;i<=n;i++){
		int k;std::cin>>k;
		int a;long long t;
		for(int j=1;j<=k;j++){
			std::cin>>a>>t;
			st[a].push_back(std::make_pair(i,t));
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=(i==j?0:0x7fffffffffffffff);
		}
	}
	for(int k=1;k<=m;k++){
		for(std::pair<int,long long>i:st[k]){
			for(std::pair<int,long long>j:st[k]){
				dist[i.first][j.first]=std::min(dist[i.first][j.first],i.second+j.second);
			}
		}
	}for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][k]<0x7fffffffffffffff&&dist[k][j]<0x7fffffffffffffff)
				dist[i][j]=std::min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(p--){
		int l,r;std::cin>>l>>r;
		if(l==r){std::cout<<"0\n";continue;}
		long long mint=0x7fffffffffffffff;
		for(std::pair<int,long long>i:st[l]){
			for(std::pair<int,long long>j:st[r]){
				if(dist[i.first][j.first]+i.second+j.second>=0){
					mint=std::min(mint,dist[i.first][j.first]+i.second+j.second);
				}
			}
		}std::cout<<mint+w[l]+w[r]<<"\n";
	}
return 0;}
