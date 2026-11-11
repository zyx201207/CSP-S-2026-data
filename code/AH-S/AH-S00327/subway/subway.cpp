#include<bits/stdc++.h>
#define make_pair mkpr
#define first fir
#define second sec
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int c,n,m,d,q;
int w[500005];
pair<int,int> query[100005];
vector<vector<pair<int,int> > >line;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++)
			scanf("%d%d",&line[i][j].fir,
				&line[i][j].sec);
	}
	for(int i=1;i<=q;i++)
		scanf("%d%d",&query[i].fir,&query[i].sec);
	
	return 0;
}
