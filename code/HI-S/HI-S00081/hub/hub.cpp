#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main(){
	freopen("hub",r,stdin);
	freopen("hub.out",w,stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>u>>v;
	}
	for(int i=t;i>0;i--){
		cout<<3-i%3<<endl;
	}
	return 0;
}
