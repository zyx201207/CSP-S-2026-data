#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,c1,a2,c2;
	cin>>a1>>c1>>a2>>c2;
	if(a1!=a2)cout<<"0000";
	else{
		if(c1[0]!=c2[0]||c1[1]!=c2[1])cout<<"1000";
		else{
			if((c1[2]<='C'&&c2[2]<='C')||(c1[2]>'C'&&c2[2]>'C')){
				if(c1[2]+1==c2[2]||c1[2]-1==c2[2])cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
	}
}
