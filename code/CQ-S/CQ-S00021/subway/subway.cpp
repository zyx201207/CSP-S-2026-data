#include<bits/stdc++.h>
using namespace std;
namespace railway{
	int c,n,m,d,q;
	int w[500005],k[505];
	vector<int>a[500005];
	vector<int>t[500005];
	long long huancheng[505][505],dst[505][505];
	int main(){
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			int aij,tij;
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>aij>>tij;
				a[aij].push_back(i);
				t[aij].push_back(tij);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)huancheng[i][j]=100000000000000;
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<a[i].size();j++){
				for(int l=0;l<j;l++){
					if(a[i][j]==a[i][l])continue;
					long long z=(long long)t[i][j]+t[i][l];
					if(z<huancheng[a[i][j]][a[i][l]]){
						huancheng[a[i][j]][a[i][l]]=z;
					}
//					huancheng[a[i][j]][a[i][l]]=min(huancheng[a[i][j]][a[i][l]],(long long)t[i][j]+t[i][l]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dst[i][j]=min(huancheng[i][j],huancheng[j][i]);
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				if(i==k)continue;
				for(int j=1;j<=n;j++){
					if(j==k||j==i)continue;
					if(dst[i][k]+dst[j][k]<dst[i][j]){
						dst[i][j]=dst[i][k]+dst[j][k];
					}
//					huancheng[i][j]=min(huancheng[i][j],huancheng[i][k]+huancheng[j][k]);
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			long long ans=100000000000000;
			for(int i=0;i<a[x].size();i++){
				for(int j=0;j<a[y].size();j++){
					long long z=dst[a[x][i]][a[y][j]]+t[x][i]+t[y][j];
					if(z<ans){
						ans=z;
					}
//					ans=min(ans,huancheng[a[x][i]][a[y][j]]+w[x]+t[x][i]+w[y]+t[y][j]);
				}
			}
			ans+=w[x]+w[y];
			cout<<ans<<'\n';
		}
		return 0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	railway::main();
	return 0;
}
