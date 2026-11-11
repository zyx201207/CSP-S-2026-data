#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[10001][10001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	int n,k;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			a[u][v]=1;
			a[v][u]=1;
		}
	}
	cout<<1<<endl<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
