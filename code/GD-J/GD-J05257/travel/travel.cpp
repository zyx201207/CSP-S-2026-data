#include <bits/stdc++.h>
using namespace std;



int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int p1=stoi(s1.substr(0,2));
		int p2=stoi(s2.substr(0,2));
		if(p1==p2){
			cout<<"1";
			
			int z1=0,z2=0;
			z1=s1[2]-'A'+1;
			if(z1==6)z1=5;
			
			z2=s2[2]-'A'+1;
			if(z2==6)z2=5;
			
			bool b1,b2;
			if(z1<=3)b1=0;
			else b1=1;
			
			if(z2<=3)b2=0;
			else b2=1;
			
			if(b1==b2){
				cout<<"1";
				if(abs(z1-z2)==1){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
