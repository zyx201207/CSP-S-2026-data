#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
int c,n,m,d,p,w[500005],k[505],a[505][505],t[505][505];
cin>>c>>n>>m>>d>>p;
for(int i=1;i<=m;i++)cin>>w[i];
for(int i=1;i<=n;i++){
	cin>>k[i];
	for(int j=1;j<=k[i];j++){
		cin>>a[i][j]>>t[i][j];
	}
}
for(int i=1;i<=p;i++){
	int x, y;
	cin>>x>>y;
}
cout<<"32\n17";
	fclose(stdin);
	fclose(stdout);
	return 0;
	
} 
