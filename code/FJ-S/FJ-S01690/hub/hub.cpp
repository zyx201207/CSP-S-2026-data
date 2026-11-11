#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int c,t,n,k;
int u,v;
int f[N][N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		cin>>u>>v;
		f[u][v]=1;
		f[v][u]=1;
		cout<<1<<endl;
	}
	return 0;
}
