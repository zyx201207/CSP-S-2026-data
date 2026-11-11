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
		if(n==k){
			cout<<0<<'\n';
			continue; 
		}
		int m=(n+1)/2;
		int ans=0;
		if(m%2==0){
			ans=m/2;
			ans-=k/4;
		}
		else{
			ans=m/2;
			k-=2;
			ans-=k/4;
		}
		cout<<ans<<'\n';
	}
}
