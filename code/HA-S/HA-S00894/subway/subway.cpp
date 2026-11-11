#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,sum=INT_MAX;
int w[500010],k[510];
int a[10][500010],t[10][500010];
bool f1[500010],f2[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(i==1)f1[j]=1;
			else f2[j]=1;
		}
	}
	for(int i=1;i<=500000;i++){
		if(f1[i]&&f2[i]){
			sum=min(sum,t[1][i]+t[2][i]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		if(n==1||((f1[x]&&f1[y])||f2[x]&&f2[y])){
			cout<<ans<<endl;
		}
		else cout<<ans+sum<<endl;
	}
	return 0;
}
/*
0 2 10 78 2
1 1 4 5 7 8 9 1 6 6
6 1 5 2 5 3 5 4 5 5 5 6 5
5 7 5 8 5 4 5 9 5 10 5
1 6
1 10
*/
