#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a1,a2,a3,a4;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a1=1;
		if(s1[1]==s2[1] && s1[0]==s2[0]){
			a2=1;
			if( (s1[2]>'C' && s2[2]>'C') || (s1[2]<='C' && s2[2]<='C') ){
				a3=1;
				if((s1[2]-1==s2[2]) || s1[2]+1==s2[2]){
					a4=1;
				}
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
