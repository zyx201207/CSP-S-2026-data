#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,s=0,g=0;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>s;
		if(g>s){
			s=g;
		}
		else{
			g=s;
		}
	}
	g=g-2;
	cout<<g;
	return 0;
}
