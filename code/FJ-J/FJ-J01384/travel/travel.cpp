#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,c1,s2,c2;
signed main(){
	freopen("travel.in","r",stdin),freopen("travel.out","w",stdout),cin>>s1>>c1>>s2>>c2;
	if(s1!=s2)puts("0000");else if(c1.substr(0,2)!=c2.substr(0,2))puts("1000");else{
		if(c1[2]<='C'&&c2[2]<='C'){
			if(abs(c1[2]-c2[2])!=1)puts("1110");else puts("1111");
		}else if(c1[2]>'C'&&c2[2]>'C')puts("1111");else puts("1100");
	}
	return 0;
} 
