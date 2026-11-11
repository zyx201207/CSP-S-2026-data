#include<bits/stdc++.h>

using namespace std;
string a=0,b=0;
int q,w;
int main(){
	freopen("travel.in","a","stdin");
	fciose(stdin);
	
	
	cin>>q;
	
	cin>>a;
	
	cin>>w;
	
	cin>>b;
	
	if(q==w){
		cout<<1;
		if(a[1]==b[1]||a[2]==b[2]){
			cout<<1;
		
		}else{
			cout<<0<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	fciose(stdout);
	freout("travel.out","a","stdout")
	return 0;
} 
