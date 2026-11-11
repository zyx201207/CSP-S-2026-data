#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,p;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		p+="1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			p+="1";
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					p+="1";
					if(s1[2]==char(s2[2]+1)||s1[2]==char(s2[2]-1)){
						p+="1";
					}else{
						p+="0";
					}
				}else{
					p+="00";
				}
			}else{
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					p+="00";
				}else{
					p+="11";
				}
			}
		}else{
			p+="000";
		}
	}else{
		p+="0000";
	}
	cout<<p;
	return 0;
} 
