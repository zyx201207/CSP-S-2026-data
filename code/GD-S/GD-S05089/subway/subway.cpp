#include<iostream>
#include<vector>
using namespace std;
typedef struct lp{
	int a,t;
} lp;
int g[500][500];
int w[500001];
int k[500]
int a[500][500000];//线，点 
int t[500][500000];
vector<int> p[500000];//点->线 
int main(){
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];//站点 
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
			p[a[i][j]].push_back(i); 
		}
	}
}
