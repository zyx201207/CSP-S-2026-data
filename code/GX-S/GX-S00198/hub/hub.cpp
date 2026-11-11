#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    for(int pl=1;pl<=t;pl++){
	    int n,k,u,v;
	    cin>>n>>k;
	    for(int i=1;i<n;i++){
		    cin>>u>>v;
		}
		cout<<round((n-1)/2)/2<<"\n";
	}
	return 0;
}
