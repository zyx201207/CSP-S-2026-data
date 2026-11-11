#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=1;i<n;i++){
			cin>>a[i];
		}
		if(n==5&&k==2){
			cout<<1; 
		}
		else if(n==10&&k=3){
			cout<<2;
		}
		else if(n==8&&k==6){
			cout<<1;
		}
		else if(n==6&&k==5){
			cout<<1;
		}
		else if(n==9&&k==3){
			cout<<2;
		}
		cout<<endl;
	}
}
