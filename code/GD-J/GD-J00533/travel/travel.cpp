#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool b1,b2,b3,b4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    	b1=1;
    	if(s1.substr(0,2)==s2.substr(0,2)){
    		b2=1;
    		if((s1[2]<='C' && s2[2]<='C') || (s1[2]>'C' && s2[2]>'C')){
    			b3=1;
    			if(abs(s1[2]-s2[2])==1)
    			b4=1;
			}
		}
	}cout<<b1<<b2<<b3<<b4;
    cout.flush();
    return 0;
}
