//15:13 zheng zai xie T2 tang le 15min
//16:02 tiao chu lai le hai da le ge shu ju sheng cheng qi, wan yi CCF shi shao ye ji ne?
//wo gan jue zhe ge fu za du hen dui a 2e8(xi
//16:03 wo jue de zhe ge bu hui bu shi zheng jie ba (bei
//qian wan yao guo ya~
//I love ccf
//yi ding yao rang wo guo ya~
//16:12 mao si ka bu diao nie~
//100pts?
#include<bits/stdc++.h>
using namespace std;
const int M=6e5,N=6e2;
int c,n,m,d,q;
long long f[N][N],w[M];
vector<int>A[M];
vector<long long>B[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int k,i=1;i<=n;++i){
		cin>>k;
		for(int a,j=1;j<=k;++j){
			long long t;
			cin>>a>>t;
			A[a].push_back(i);
			B[a].push_back(t);
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			f[i][j]=1e18;
			f[i][i]=0;
		}
	for(int i=1;i<=m;++i)
		for(int j=0;j<(int)A[i].size();++j)
			for(int k=j+1;k<(int)A[i].size();++k)
				if(f[A[i][k]][A[i][j]]>B[i][j]+B[i][k])f[A[i][k]][A[i][j]]=f[A[i][j]][A[i][k]]=B[i][j]+B[i][k];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				if(f[i][k]!=1e18&&f[k][j]!=1e18&&f[i][k]+f[k][j]<f[i][j])
					f[i][j]=f[i][k]+f[k][j];
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(int i=0;i<(int)A[x].size();++i)
			for(int j=0;j<(int)A[y].size();++j)
				if(f[A[x][i]][A[y][j]]+B[x][i]+B[y][j]<ans)
					ans=f[A[x][i]][A[y][j]]+B[x][i]+B[y][j];
		cout<<ans+w[x]+w[y]<<'\n';
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
