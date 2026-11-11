#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v; 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int d=(n+1)/2;
		for(int i=1;i<n;i++)
			cin>>u>>v;
		if(k==n){
			cout<<"0"<<"\n";
			continue;
		}
		if(k>=d){
			cout<<"1"<<"\n";
			continue;
		}
		k--;
		if(d%2==1){
			int p=(d+1)/2;
			if(k%2==0)	cout<<p-k/2<<"\n";	
		}	
		else{
			
		}
	}
	return 0;
}
