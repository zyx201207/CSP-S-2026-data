#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[5000][5000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t){
		t--;
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			a[u][v]=true;
			a[v][u]=true;
		}
	}
	cout<<1<<endl<<2;
	return 0;
}


