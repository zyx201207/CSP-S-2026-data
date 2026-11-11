#include<bits/stdc++.h>
using namespace std;
int a[505][50005],t[505][50005];
int b[505][505];
int v[50005];
int w[50005];
int k[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			b[i][j]=t[i][j];
		}
	}
	
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		int sum=w[x]+w[y];
		
		cout<<sum+b[x][y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
} 
 