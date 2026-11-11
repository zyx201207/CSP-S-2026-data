//GZ-S00325 贵阳市南明区华麟学校 陈锦江
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100,M=1500;
long long w[N],k[M],a[M][M],t[M][M],ans;
vector<int>vis;
struct node{
	int id,c,v;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
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
		int u,v;
		cin>>u>>v;
		cout<<w[u]+t[u][v]<<endl;
	}
	return 0;
}

