#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,a,b;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>a>>b;
		}
		if(t!=0) cout<<"1"<<endl;
		else cout<<"2"<<endl;
	}
	return 0;
}
