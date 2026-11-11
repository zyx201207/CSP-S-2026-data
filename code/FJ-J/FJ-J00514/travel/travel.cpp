#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		string p1=s1.substr(0,2),p2=s2.substr(0,2);
		if(p1!=p2){
			cout<<"1000";
			return 0;
		}
		else{
			string z1=s1.substr(2,1),z2=s2.substr(2,1);
			if(z1=="A" and z2=="B" or z1=="A" and z2=="C" or z1=="B" and z2=="A" or z1=="B" and z2=="C" or z1=="C" and z2=="A" or z1=="C" and z2=="B" or z1=="D" and z2=="F" or z1=="F" and z2=="D"){
				if(z1=="A" and z2=="B" or z1=="B" and z2=="A" or z1=="B" and z2=="C" or z1=="C" and z2=="B" or z1=="D" and z2=="F" or z1=="F" and z2=="D"){
					cout<<"1111";
					return 0;
				}
				else{
					cout<<"1110";
					return 0;
				}
			}	
			else{
				cout<<"1100";
				return 0;
			}
		}
	}
	
		
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
