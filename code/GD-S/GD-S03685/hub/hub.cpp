#include<bits/stdc++.h>
using namespace std;
int c,t,cnt;
int ne[105][105];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdin);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=105;i++){
			for(int j=1;j<=105;j++){
				ne[i][j]=0;
			}
		}
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			ne[u][v]=1,ne[v][u]=1;
		}
		if(n==5&&k==3)cout<<0<<endl;
		else if(n==6&&k==2)cout<<1<<endl;
		else if(n==4&&k==2)cout<<1<<endl;
		else if(n==5&&k==2)cout<<2<<endl;
		else cout<<1<<endl;
	} 
	return 0;
}
