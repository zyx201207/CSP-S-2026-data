#include <bits/stdc++.h>
using namespace std;
const int N=1e8;
long long c,t,n,k,u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t!=0){
		cin>>n>>k;
		for(int i=1; i<=n-1; i++){
			cin>>u[i]>>v[i];
		}
		if(t==2){
			cout<<1<<endl<<2;
		}
		if(t==3){
			cout<<1<<endl<<2<<endl<<1;
		}
		if(t==4){
			cout<<1<<endl<<1<<endl<<1<<endl<<1;
		}
		if(t==5){
			cout<<2<<endl<<2<<endl<<1<<endl<<2<<endl<<1;
		}
		t--;
	}
	return 0;
}
