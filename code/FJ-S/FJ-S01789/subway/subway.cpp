#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,mx,now;
int w[505],t[505][505],a[505][505];
int tw[505][505];
void solv(){
	int x,y,mx=99999999;
	cin>>x>>y;
	for(int i=1;i<=n;i++){
		int tm=w[x]+w[y];
		if(tw[i][x]==1){
			tm+=t[i][x];
			if(tw[i][y]==1){
				tm+=t[i][y];
				mx=min(mx,tm);
			}              
		}
	}
	cout<<mx<<"\n";
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];tw[i][a[i][j]]=1;
			cin>>t[i][j];
		}
	}
	while(q--)solv();
	return 0;
}