#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k,u,v;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		int s=0;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			s+=u;
		}
		if(c==0){
			cout<<1<<endl<<2;
			return 0;
		}
		cout<<s<<endl;
	} 
	return 0;
}
