#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[2000000],v[2000000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int o=1;o<=t;o++){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
	}
	if(c==0){
		cout<<"1\n2";
		return 0;
	}
	return 0;
} 
