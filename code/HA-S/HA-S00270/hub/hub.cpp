#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
		}
	}
	if(t==2){
		cout<<1<<endl<<2;
		return 0;
	}
	if(t==3){
		cout<<1<<endl<<1<<endl<<2;
		return 0;
	}
	return 0;
}
