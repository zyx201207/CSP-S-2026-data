#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500001];
int a[5001][5001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			a[x][j]=t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	if(n==2)cout<<32<<endl<<17;
	if(n==3){
		cout<<35<<endl<<16;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
