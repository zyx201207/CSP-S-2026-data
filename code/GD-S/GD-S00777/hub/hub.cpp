#include<bits/stdc++.h>
using namespace std;
long long n,c,t,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		for(int j=1;j<n;j++){
			cin>>u>>v;
		}
		cout<<abs(u-v)<<endl;
	}
	return 0;
} 
