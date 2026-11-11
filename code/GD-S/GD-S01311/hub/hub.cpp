#include<bits/stdc++.h>
using namespace std;
long long t,n,a;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>a;
		if(n==a)cout<<"0\n";
		else if(n&1){
			if(a>=n/2)cout<<"1\n";
			else cout<<((n-1)/2-a+3)/4+1;
		}else cout<<"1\n";
		n--;
		while(n--)cin>>a>>a;
	}
	return 0;
}
