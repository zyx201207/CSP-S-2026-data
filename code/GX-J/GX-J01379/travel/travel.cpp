#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
cin>>a>>b>>c>>d;
if(a==c){
	cout<<1;
	}
else cout<<0;
	if(b/10==d/10){
		cout<<1;
		
		}
else cout<<0;
else if(b%10=="a"||b%10=="b"||b%10=="c"&&d%10=="a"||d%10=="b"||%10=="c"){
		cout<<1;
		
	}
	else if(b%10=="d"||b%10=="e"&&d%10=="d"||d%10=="e"){
		cout<<1;
		}
		else cout<<0;
	
	
	
	
	return 0;
}
