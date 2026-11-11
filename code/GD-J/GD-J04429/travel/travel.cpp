#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		bool f=false;
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]) f=true;
		}
		if(f){
			cout<<"1000";
		}
		else{
			if((s1[2]>'C')!=(s2[2]>'C')){
				cout<<"1100";
			}
			else{
				if((s1[2]-1==s2[2]) || (s2[2]-1==s1[2])){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
		}
	}
	return 0;
} 
