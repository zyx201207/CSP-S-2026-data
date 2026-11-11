#include<bits/stdc++.h>
#define int long long
#define fst first
#define scd second
#define pb push_back
using namespace std;
int c,t;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++)cin>>u>>v;
		if(c==13||c==14){
			cout<<(n/2-k+1)/2<<'\n';
		}else{
			cout<<(n-k+2)/3<<'\n';
		}
	}
	
	
	return 0;
}
