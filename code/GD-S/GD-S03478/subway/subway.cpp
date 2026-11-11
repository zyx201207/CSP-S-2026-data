#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y;
};node r[100001];
long long jzs=0;
long long c,n,m,d,q,w[500001];node k[501][50001];long long maxx=0;long long a[9000][9000],b[9000][9000];
//vector<vector<long long>>g;
long long dfs(long long x,long long y,long long sum){
	if(x==y)return sum;
	if(b[x][y])return 9999999;
	b[x][y]=1;
	long long boss=0;
	for(int i=1;i<=n;i++){
		if(a[x][i]!=0){
			//cout<<"wwdqed";
			sum+=a[x][i];
			for(int j=1;j<=k[i][0].x;j++)
			boss=min(dfs(k[i][j].x,y,sum),boss);
			//cout<<dfs(k[i][j].x,y,sum);
		}
		//cout<<"dawd";
	}
	 if(x==jzs)cout<<boss;
	return 0;
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		long long y;
		cin>>k[i][0].x;
		for(int j=1;j<=k[i][0].x;j++){
			//node x; 
			cin>>k[i][j].x>>k[i][j].y;
			a[k[i][j].x][i]=k[i][j].y;
			//cout<<a[k[i][j].x][i]<<'\n';
			 maxx+=k[i][j].x;
			//if(j>2)g[x.x].push_back(x.y);
			
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i].x>>r[i].y;
		long long sum=w[r[i].x]+w[r[i].y];
		cout<<maxx+sum<<'\n'; 
		/*jzs=r[i].x;
		dfs(r[i].x,r[i].y,sum);
		*/
	}
	return 0;
} 
