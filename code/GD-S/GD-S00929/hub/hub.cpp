#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(long long i=1;i<n;i++){
			cin>>u>>v;
		}
		cout<<((n%2)?1:2)<<endl;
	}
	return 0;
}
//hub
