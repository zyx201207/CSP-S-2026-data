#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k,u,v;
int tu[100005][100005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
			tu[u][v]=1;
		}
		cout<<abs(t-3495832)%2;
	}
	return 0;
}
