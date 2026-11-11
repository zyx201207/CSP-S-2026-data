#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[510];
int t[510][500005];
long long sum;
long long T;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a;j<=k;j++){
			cin>>a>>t[i][j];
			T=t[i][j];
		}
	}
	while(q--){
		int x,y;
		sum+=w[x]+w[y]+(y-x)*T;
		cout<<sum<<'\n'; 
	}
}
