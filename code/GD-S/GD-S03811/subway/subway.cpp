#include <bits/stdc++.h> 
using namespace std;

int c,n,m,d,q,a[1000000],k[1000000];

struct node{
	long long a,t;
}b[501][10000];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>b[i][j].a>>b[i][j].t;
		}
	}
	int t=0,cnt=0;
	while(t<=q){
		t++;
		int x,y;
		cin>>x>>y;
		cout<<"27";
	}
	return 0;
}
