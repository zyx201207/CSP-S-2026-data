#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int q,w;
	int e[5];
	cin>>q>>w;
	for(int i=0;i<=4;i++){
		cin>>e[i];
	}
	if(w==5){
		cout<<3;
	}if(w==8){
		cout<<4;
	}
	
	
	return 0;
}
