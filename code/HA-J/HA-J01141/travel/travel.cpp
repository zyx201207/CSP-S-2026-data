#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string a1,a2,b1,b2;
	if(c1==c2){
		cout<<1;
		for(int i=0;i<s1.size()-1;i++){
			a1+=s1[i];
		}
		for(int i=0;i<s2.size()-1;i++){
			a2+=s2[i];
		}
		if(a1==a2){
			cout<<1;
			b1=s1[2];
			b2=s2[2];
			if(((b1=="A"||b1=="B"||b1=="C")&&(b2=="A"||b2=="B"||b2=="C"))||((b1=="D"||b1=="F")&&(b2=="D"||b2=="F"))){
				cout<<1;
				if((b1=="A"&&b2=="B")||(b1=="B"&&b2=="C")||(b1=="B"&&b2=="A")||(b1=="C"&&b2=="B")||(b1=="D"&&b2=="F")||(b1=="F"&&b2=="D")){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	
	
	return 0;
}
