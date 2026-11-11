#include <bits/stdc++.h>
using namespace std;
long long dis[3305][3305];
struct node{
	long long i,w;
};
long long w[100005];
long long k[10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		cin>>k[i];
		vector<node> qq;
		for(int j=1;j<=k[i];j++){
			int aa,tt;
			cin>>aa>>tt;
			for(int k=0;k<qq.size();k++){
				dis[qq[k].i][aa]=min(dis[qq[k].i][aa],qq[k].w+tt);
				dis[aa][qq[k].i]=min(dis[aa][qq[k].i],qq[k].w+tt);
			}
			qq.push_back(node{aa,tt});
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		cout<<dis[l][r]+w[l]+w[r]<<'\n';
	}
	
	return 0;
}