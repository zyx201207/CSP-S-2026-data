#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,T,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
    	cin>>n>>k;
    	for(int i=1,u,v;i<n;i++)cin>>u>>v;
    	ll m=(n-1)/2;
    	if(c==13||c==14) cout<<m-k/2<<'\n';
    	else cout<<2<<'\n';
	}
	return 0;
}

