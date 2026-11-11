#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		if(s1[0]!=s2[0] || s1[1]!=s2[1]){
			cout<<1000;
			return 0;
		}
		else{
			char x=s1[2],r=s2[2];
			if((x<='C' && r>='D') || (x>='D' && r<='C')){
				cout<<1100;
				return 0;
			}
			else{
				if(x=='D' || r=='D' || x=='B' || r=='B'){
					cout<<1111;
					return 0;
				}
				else if((x=='A' && r=='C') || (x=='C' && r=='A')){
					cout<<1110;
					return 0;
				}
			}
		}
	}
	return 0;
}
