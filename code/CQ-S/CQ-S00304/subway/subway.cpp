#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
long long t[501][100001],w[500001];
bool a[501][100001],mp[501][100001];
long long res,minn;
void dfs(int x,int y){
	if(x==y){
		res=min(res,minn);
		return ;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(x!=i){
				if(a[j][x]==1&&a[j][i]==1){
					if(mp[x][i]!=1&&mp[i][x]!=1){
						mp[x][i]=1;
						mp[i][x]=1;
						minn+=t[j][x]+t[j][i];
						dfs(i,y);
						mp[x][i]=0;
						mp[i][x]=0;
						minn-=(t[j][x]+t[j][i]);						
					}
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int b,r;
			cin>>b>>r;
			a[i][b]=1;
			t[i][b]=r; 
		}
    }
    while(q--){
    	int x,y,sum=0;
    	res=9999999999;
    	cin>>x>>y;
    	sum+=(w[x]+w[y]);
    	minn=0;
    	dfs(x,y);
    	sum+=res;
    	cout<<sum<<endl;
	}
	return 0;
}

