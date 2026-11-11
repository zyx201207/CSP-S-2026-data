#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,x,y;
	char a,b;
	cin>>n>>x>>a>>m>>y>>b;
	if(n!=m){
		cout<<"0000";
	}
	else if(x!=y){
		cout<<"1000";
	}
	else if(a>='D' && b<='C' || b>='D' && a<='C'){
		cout<<"1100";
	}
	else if(a=='A' && b=='C' || a=='C' && b=='A'){
		cout<<"1110";
	}
	else if(a!='A' && b!='C' || a!='C' && b!='A'){
		cout<<"1111";
	}
	return 0;
} 
