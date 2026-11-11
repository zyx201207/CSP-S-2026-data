#include<bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;
const long long maxn=505;
long long res[505][505];
vector<long long>tim;
vector<vector<long long> >line;
vector<vector<long long> >linet;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	tim=vector<long long>(m+1);
	for(long long i=1;i<=m;i++){
		cin>>tim[i];
	}
	line=vector<vector<long long> >(m+1,vector<long long>(0));
	linet=vector<vector<long long> >(m+1,vector<long long>(0));	
	for(long long i=1;i<=n;i++){
		line[i].reserve(d);
		linet[i].reserve(d);
		long long k;long long a,t;
		cin>>k;
		for(long long j=0;j<k;j++){
			cin>>a>>t;
			line[a].push_back(i);
			linet[a].push_back(t);
		}
	}
	for(long long i=1;i<505;i++){
		for(long long j=1;j<505;j++){
			if(i==j) res[i][j]=0;
			else res[i][j]=100000000000000000;
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=0;j<line[i].size();j++){
			for(long long k=j+1;k<line[i].size();k++){
				res[line[i][j]][line[i][k]]=min(linet[i][j]+linet[i][k],res[line[i][j]][line[i][k]]);
				res[line[i][k]][line[i][j]]=min(linet[i][k]+linet[i][j],res[line[i][k]][line[i][j]]);
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			for(long long k=1;k<=n;k++){
				res[i][j]=min(res[i][j],res[i][k]+res[k][j]);
			}
		}
	}
	long long x,y,ans;
	while(q--){
		long long ans=100000000000000000;
		cin>>x>>y;
		for(long long i=0;i<line[x].size();i++){
			for(long long j=0;j<line[y].size();j++){
				ans=min(ans,res[line[x][i]][line[y][j]]+linet[x][i]+linet[y][j]);
		}
		}
		ans+=tim[x];
		ans+=tim[y];
		cout<<ans<<'\n';
	}
	cout.flush();
	return 0;
}
