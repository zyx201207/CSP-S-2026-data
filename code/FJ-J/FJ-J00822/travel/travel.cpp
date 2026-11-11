#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,c2,s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		if(c2.substr(0,2)==s2.substr(0,2)){
			if((c2[2]<='C'&&s2[2]<='C')||(c2[2]>'C'&&s2[2]>'C')){
				if(min(c2[2],s2[2])+1==max(c2[2],s2[2]))
					puts("1111");
				else puts("1110");
			}else puts("1100");
		}else puts("1000");
	}else puts("0000");
	return 0;
} 
