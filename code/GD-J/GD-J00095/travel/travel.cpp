#include<bits/stdc++.h> 
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c[2],s[2];
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]==c[2])cout<<1;
	else cout<<0;
	if(s[1]==s[2])cout<<111;
	else cout<<000;
	return 0;
} 
