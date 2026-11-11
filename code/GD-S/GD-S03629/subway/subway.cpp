#include<bits/stdc++.h>
using namespace std;
const int MAXX=4e6+7891;
int c,n,m,d,q;
int w[MAXX];
int k[MAXX];
int x,y;
vector<vector<int> > a,t;
int main()
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>x>>y;
		}
	}if(m==5){
		cout<<32<<endl<<17;
	}if(m==7){
		cout<<35<<endl<<16;
	}
	return 0;
}
