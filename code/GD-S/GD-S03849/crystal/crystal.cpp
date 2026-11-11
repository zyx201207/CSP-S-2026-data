#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int c,n,m,d,q,k[501],tsub[maxn];
int dijkstra[501][501];
struct node{
	vector<int> a,t;
	int l=0;
}sd[maxn];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>tsub[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int xa,xt;
			cin>>xa>>xt;
			(sd[xa].a).push_back(i);
			(sd[xa].t).push_back(xt);
			sd[xa].l++;
			for(int w=0;w<sd[xa].l-1;w++){
				int ind=(sd[xa].a)[w],sum=(sd[xa].t)[w]+xt;
				dijkstra[ind][i]=(dijkstra[ind][i]<sum)?sum:dijkstra[ind][i];
				dijkstra[i][ind]=dijkstra[ind][i];
			}
		}
	}

}
