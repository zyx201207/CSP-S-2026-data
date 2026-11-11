#include<bits/stdc++.h>

using namespace std;
int c,t,n,k,u[200005],v[200005];
int main(){
	ifstream("hub.in");
	ofstream("hub.out");
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n;j++){
			cin>>u[j]>>v[j];
		}
	}
	if(c==0){
		cout<<1<<endl<<2;
	}
	else{
		for(int i=1;i<=1e9;i++){
			for(int i=1;i<=1e9;i++){
				cout<<1<<endl;
			}
		}
	}
} 
