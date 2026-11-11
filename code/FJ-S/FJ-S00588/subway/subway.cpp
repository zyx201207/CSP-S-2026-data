/*



*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=0x3f3f3f3f3f3f ;
int c,n,m,d,q,w[500010],ff[510][510];
struct node{
	int id,w;
};
vector<node> vec[500010];
int r(){
	int dx=0,x=1;
	char xx=getchar();
	for(;!isdigit(xx);xx=getchar())
		if(xx=='-')
			x=-1;
	for(;isdigit(xx);dx=dx*10+xx-48,xx=getchar());
	return dx*x;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	c=r();
	n=r();
	m=r();
	d=r();
	q=r();
	for(int i=1;i<=m;w[i]=r(),i++);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j)
				continue;
			ff[i][j]=MAX;
		}
	for(int i=1;i<=n;i++){
		int k;
		k=r();;
		for(int j=1;j<=k;j++){
			int a,b;
			a=r();
			b=r();
			vec[a].emplace_back((node){i,b});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<vec[i].size();j++)
			for(int k=j+1;k<vec[i].size();k++){
				ff[vec[i][j].id][vec[i][k].id]=min(ff[vec[i][j].id][vec[i][k].id],vec[i][j].w+vec[i][k].w);
				ff[vec[i][k].id][vec[i][j].id]=min(ff[vec[i][k].id][vec[i][j].id],vec[i][j].w+vec[i][k].w);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ff[i][j]=min(ff[i][j],ff[i][k]+ff[k][j]);
//	for(int i=1;i<=n;cout<<'\n',i++)
//		for(int j=1;j<=n;j++)
//			cout<<ff[i][j]<<' ';
	for(int o=1;o<=q;o++){
		int a,b,ans=MAX;
		a=r();
		b=r();
		for(int i=0;i<vec[a].size();i++)
			for(int j=0;j<vec[b].size();j++){
//				cout<<vec[a][i].id<<' '<<vec[b][j].id<<'\n';
				ans=min(ans,ff[vec[a][i].id][vec[b][j].id]+vec[a][i].w+vec[b][j].w);
			}
		cout<<ans+w[a]+w[b]<<'\n';
	}
	return 0;
}

