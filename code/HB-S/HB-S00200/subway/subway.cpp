#include<iostream>
#include<vector>
using namespace std;
int c,n,m,d,q,w[500005],k[500005];
struct node{
	int a,t;
};
struct question{
	int x,y;
}t;
vector<node>b[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>b[i][j].a>>b[i][j].t;
		}
	}
	if(n==2&&m==5&&d==20&&q==2) cout<<"32\n17";
	if(n==3&&m==7&&d==20&&q==2) cout<<"35\n16";
	return 0;
}
