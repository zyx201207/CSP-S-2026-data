#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t>>n>>k;
	if(n<0){
		cout<<k;
	}else if(n>10){
		cout<<n;
	}else{
		cout<<t;
	}
	
	return 0;
}
