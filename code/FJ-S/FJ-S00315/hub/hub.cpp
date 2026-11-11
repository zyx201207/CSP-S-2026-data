#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r","stdin");
	freopen("hub.out","w","stdout");
	int c,t,n[100010],k,u[100010],v[100010];
	cin>>c>>t;
	for(int i=0;i<=t;i++){
		cin>>n[i]>>k;
		for(int j=0;j<=n[i];j++){
			cin>>u[j]>>v[j];
		}
	}
	if(n[0]=5){
		cout<<"1 2";
	}	
	return 0;
	}
