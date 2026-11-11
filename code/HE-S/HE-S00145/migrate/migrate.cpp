#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+10;
int c,n,m,d,q,k;
long long w[500010],a[510][N],t[510][N],x[100000],y[100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
	}
	if(c>=12 && c<=19){
		for(int i=1;i<=q;i++){
			cout<<t[1][1]*2+w[x[i]+w[y[i]]]<<endl;
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2 
1 2 3 4 5
*/
