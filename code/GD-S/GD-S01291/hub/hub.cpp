#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
    freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		int n,k,a[200006][200006],u,v;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
			a[u][v]=1;
		}
		cout<<n<<endl;
	}
	return 0;
	
} 
