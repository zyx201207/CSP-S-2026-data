#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int s,e;
int w[500005];
int k[505];
int a[505][505];
int t[505][505];
bool vis[505];

//void f(int k){
	
//}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		cin>>s>>e;
		int sum=w[s]+w[e];
		
		
		
		cout<<sum<<'\n';
	}
}
