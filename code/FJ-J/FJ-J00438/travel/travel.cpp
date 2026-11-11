#include <bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2,ss1; 
int main(){//É¾×¢ÊÍ£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){ 
		cout<<1;
		string ss1,ss2;
		ss1+=s1[0];
		ss1+=s1[1];
		ss2+=s2[0];
		ss2+=s2[1];
		if(ss1==ss2){
			cout<<1;
			if(s1[2]>='D'){
				if(s2[2]>='D'){
					cout<<"11";
					return 0;
				}
				else{
					cout<<"00";
					return 0;
				}
			}else{
				if(s2[2]<='C'){
					cout<<1;
					if(abs(s1[2]-s2[2])==2){
						cout<<"0";
						return 0;
					}else{
						cout<<"1";
						return 0;
					}
				}else{
					cout<<"00";
					return 0;
				}
			}
			
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}

}
