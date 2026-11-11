#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int p=1;p<=t;p++){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		if(n>=(n-1)/2){
			cout<<1<<endl;
		}
		else if(k==1){
			cout<<(n-1)/2/2+1<<endl;
		}
		else if(k==2){
			cout<<((n+1)/2+1)/2+1<<endl;
		}
		else{
			cout<<((n+1)/2+k-1)/k<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
