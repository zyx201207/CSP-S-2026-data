#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
long long w[N],sum,ans=1e16;
int k[505],a[N][N],t[N][N],x,y;
void dfs(int _k,int step,long long T){
	if(step==y){
		ans=min(ans,T);
		return ;
	}
	for(int i=_k;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==step||a[i][j]==x){
				T+=t[i][j];
				dfs(i+1,j,T);
				T-=t[i][j];
			}
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=0;
		int z=0,c=0;
		sum+=w[x]+w[y];
		for(int _i=1;_i<=n;_i++){
			for(int j=1;j<=k[_i];j++){
				if(x==a[_i][j]){
					z=_i;
					c=j;
					break;
				}
			}
			if(z!=0)break;
		}
		dfs(z,c,0);
		sum+=ans;
		//cout<<sum<<endl;
	}
	return 0;
}

