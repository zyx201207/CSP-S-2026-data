#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500001];
int a[501][500001];
long long k[501];
vector<long long>p[500001];
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int T;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>T;
			if(j>=2){
				p[a[i][j]].push_back(a[i][j-1]);
				p[a[i][j-1]].push_back(a[i][j]);
			}
		}
	}
	while(q){
		int stra,en;
		cin>>stra>>en;
		cout<<w[stra]+w[en]+(n-1)*2*T;
	}
}
