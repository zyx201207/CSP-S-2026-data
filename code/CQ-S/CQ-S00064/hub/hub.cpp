#include<bits/stdc++.h>
using namespace std;
int t;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%2==1){
			cout<<1;
		}
		else{
			cout<<2;
		}
	}
	
	return 0;
} 
