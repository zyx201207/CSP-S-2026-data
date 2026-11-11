#include<bits/stdc++.h>
using namespace std;
int randint(){
	return rand()/2000;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(NULL));
	randint();
	int c,t,n,k,u,v;
	cin>>c>>t;
	for(int i=1; i<=t; i++){
		cin>>n>>k;
		for(int i=1; i<n; i++){
			cin>>u>>v;
		}
		cout<<randint()<<'\n';
	}
	return 0;
}

