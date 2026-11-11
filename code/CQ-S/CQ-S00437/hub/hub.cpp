#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
vector<int>a[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&u,&v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
	}
	return 0;
} 
