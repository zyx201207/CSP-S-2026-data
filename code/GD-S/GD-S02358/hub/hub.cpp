#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		cout<<n%k<<endl;
	}
	return 0;
}

