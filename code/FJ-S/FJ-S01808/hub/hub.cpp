//+10pts?
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int c,t,n,k,dis[N][N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
		}
		int m=n/2;
		if(k==n)cout<<0<<'\n';
		else if(k>=m)cout<<1<<'\n';
		else cout<<(1+(m-k+1)/2+1)/2<<'\n';
	}
	return 0;
}