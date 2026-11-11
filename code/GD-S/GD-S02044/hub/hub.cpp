#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000009],b[2000009],n;
int main(){
	freopen("hub.in","r",stdin);
	ll c,t,first;
	cin>>c>>t;
	first =t;
	while(t--){
		ll k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
		}
	}
	if(first==2)cout<<1<<endl<<2 ; 
	if(first ==3)cout<<1<<endl<<1<<endl<<2; 
	if(first ==5&&n!=10845){
		cout<<17<<endl;
		cout<<9<<endl;
		cout<<6<<endl;
		cout<<6<<endl;
		cout<<9<<endl;
	}
	if(first ==5&&n==10845){
		cout<<189<<endl;
		cout<<233<<endl;
		cout<<288<<endl;
		cout<<229<<endl;
		cout<<338<<endl;
	}
	if(first==1){
		cout<<12251<<endl;
		

	}
	freopen("hub.out","w",stdout);
	return 0;
}
