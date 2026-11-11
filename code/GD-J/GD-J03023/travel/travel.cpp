#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,a1,a2;
	char b1,b2;
	bool k;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		b1=s1[2];
		b2=s2[2];
		a1=s1[0]+s1[1];
		a2=s2[0]+s2[1];
		if(a1!=a2){
			cout<<"1000";
			return 0;
		}
		else{
			k=(int(b1)<=67);
			if((int(b2)<=67)^k){
				cout<<"1100";
				return 0;
			}
			else{
				if((int(b1)+1!=int(b2))&&(int(b1)-1!=int(b2))){
					cout<<"1110"<<endl;
					return 0;
				}
				else{
					cout<<"1111";
					return 0;
				}
			}
		}
	}
	return 0; 
} 
