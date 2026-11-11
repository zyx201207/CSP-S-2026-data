#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		int m=n/2;
		if(k<=m+1){
			cout<<(m+1)/k;
		}
		else if(k!=n){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
