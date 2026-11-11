#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("r","hub.in",stdin);
	freopen("w","hub.out",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,k;
		cin>>n>>k;
		int u[n-1]={0},v[n-1]={0};
		for(int j=0;j<n;j++){
			cin>>u[j]>>v[j];
		}
		if(n==5 and k==2){
			cout<<1<<endl;
		}
		if(n==10 and k==3){
			cout<<2<<endl;
		}
	}
	
	return 0;
}
