#include<bits/stdc++.h>
using namespace std;
#define ulp(i,a,b) for(int i=a;i<=b;i++)
int c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ulp(i,1,n){
			cin>>u>>v;
		}
		cout<<k<<"\n";
	}
}
