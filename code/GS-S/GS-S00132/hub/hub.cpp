#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,q,w;
int main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>q>>w;
		cout<<ceil(k*1.0/2)<<"\n";
	}
	return 0;
}

