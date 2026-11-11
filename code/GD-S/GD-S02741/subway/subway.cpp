#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long c,n,m,d,q,tans=0;
long long w[N],k[N],a[N],t[N],x[N],y[N];//w从地铁站到站厅，t从站听到站台 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>a[i]>>t[i];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		tans+=t[x[i]]+w[x[i]]+t[y[i]]+w[y[i]];
		cout<<tans<<endl;		
	}
	return 0;
} 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
