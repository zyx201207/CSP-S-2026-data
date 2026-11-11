#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int tmptmptmp,t;
    cin>>tmptmptmp>>t;
    while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		if(n<=k){
			cout<<0<<endl;
		}
		else{
			cout<<(n/(k+1))+1;
		}
	}
    return 0;
}
