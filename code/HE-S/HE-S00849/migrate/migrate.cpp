#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
int a[500005];
map<int,long long> ma;
long long ans;
long long mi=1e18;
int mb;
void bfs(int x,long long  step){
	if(x==mb){
		ma[step]++;
		mi=min(mi,step);
		return ;
	}
	for(int i=n;i>x;i--){
		if(abs(a[x]-a[i])<=m){
			bfs(i,step+1);
		}
	}
}
void bfs_1(){
	mb=n;
	for(int i=1;i<=n;i++){
		mb=n;
		while(mb>=1){
			if(i==mb){
				mb--;
				continue;
			}
			mi=1e18;
			bfs(i,1);
			if(ma[mi]%2==1){
				ma[mi]--; 
			}
			ans+=ma[mi]/2;
			ma.clear();
			mb--;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		bfs_1();
		cout<<ans;
	}
	return 0;
} 
