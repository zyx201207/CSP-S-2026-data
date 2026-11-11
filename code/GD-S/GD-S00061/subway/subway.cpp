#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[250000+10];
long long k[510],a[510][30],t[510][30];
long long x[100000+10],y[100000+10];
vector<long long> xianlu[250000+10];
long long shijian[250000+10];
long long xianlushu[250000+10];
vector<long long> xianglindian[250000+10];
long long xianglindianshu[250000+10];
long long shangyige[250000+10];
bool f[250000+10];
bool tongxianlu(long long _a,long long _b){
	for(int i=0;i<xianlushu[_a];i++){
		for(int j=0;j<xianlushu[_b];i++){
			if(xianlu[_a][i]==xianlu[_b][j]){
				return true;
			}
		}
	}
	return false;
}
void bfs(long long node,long long zhong){
	queue<long long> qu;
	qu.push(node);
	long long fr=qu.front();
	while(fr!=zhong){
		fr=qu.front();
		for(long long i=0;i<xianglindianshu[fr];i++){
			long long dangqian=xianglindian[fr][i];
			if(f[dangqian]){
				continue;
			}
			qu.push(dangqian);
			f[dangqian]=true;
			shangyige[dangqian]=fr;
			if(tongxianlu(shangyige[fr],dangqian)){
				shijian[dangqian]=shijian[fr];
			}else{
				shijian[dangqian]=shijian[fr]+2*t[1][1];
			}
		}
	}
	cout<<shijian[zhong]+w[zhong]+w[node]<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(f,false,sizeof(f));
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			xianlu[a[i][j]].push_back(i);
			xianlushu[a[i][j]]++;
			xianglindianshu[a[i][j]]++;
			xianglindianshu[a[i][j-1]]++;
			xianglindian[a[i][j]].push_back(a[i][j-1]);
			xianglindian[a[i][j-1]].push_back(a[i][j]);
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		bfs(x[i],y[i]);
	}
	return 0;
}
