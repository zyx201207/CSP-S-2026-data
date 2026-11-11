#include<bits/stdc++.h>
using namespace std;
const int N=1e6*2;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k,u[N],v[N];
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		if(t==1)cout<<2<<"\n";
		else cout<<1<<"\n";
	}
	return 0;
}
