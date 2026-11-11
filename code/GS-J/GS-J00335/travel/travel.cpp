#include<bits/stdc++.h>
using namespace std;
char s[3];
int c[3];
int main(){
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
cin>>c[1]>>s[1]>>c[2]>>s[2];
if(c[1]==c[2]){
	cout<<"111";
    if((s[1]==s[2]+1)||(s[1]==s[2]-1)){
    	cout<<'1';
	}
	else{
		cout<<'0';
	}
}
else{
	cout<<"0000";
}
return 0;
}
