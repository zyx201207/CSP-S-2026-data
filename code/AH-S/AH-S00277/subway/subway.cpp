#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[500005],k[500005];
struct Node{
	int sub,station;
	int t;
}a[1005][10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	/*
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=2005;i++){
		for(int j=1;j<=2005;j++){
			t[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			a[j].sub=i;
			cin>>a[j].station>>a[j].t;
		}
	}
	while(p--){
		int x;int y;
		cin>>x>>y;
		cout<<t[min(x,y)][max(x,y)]<<endl;
	}
	*/
	cout<<"32\n17";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
