//GZ-J00594 张艺铭 贵阳中天中学 
#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
freopen("travel.in","r",stdin); 
freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		if(s1[1]==s2[1]){
			cout<<"1";
		}
			else{
				cout<<"000";
				return 0;
			}
		if(s1[2]+s2[2]!=131||s1[2]+s2[2]!=132||s1[2]+s2[2]!=138){
			if(s1[2]+s2[2]==135||s1[2]+s2[2]==137){
			cout<<"00";
			return 0;
		}
		else{
			cout<<"1";
		}
				if(s1[2]+s2[2]==131||s1[2]+s2[2]==133||s1[2]+s2[2]==138){
					cout<<"1";
				}
				else {
					cout<<"0";
				}
	} 
}

return 0;
}
