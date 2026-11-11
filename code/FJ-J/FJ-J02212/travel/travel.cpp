#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int c,s,n,m;
	cin>>c>>n>>s>>m;
	if(c==02 && s==02){
		cout<<1;
	}else{
		cout<<0000;
	}
	if(n%10==m%10){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 

