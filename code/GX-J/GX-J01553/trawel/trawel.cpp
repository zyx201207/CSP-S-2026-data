#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string1.in","r",stdin);
	freopen("string.out","w",stdout);
	string c1,c2,s1,s2;
	string sc;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		sc="1";
		if(s1[1]==s2[1] && s2[2]==s1[2]){
				sc+="1";
		}
		else{
			sc+="0";
		}
		if(s1[1]==s2[1] && s2[2]==s1[2]){
			if(s1[3]>='A' && s1[3]<='C' && s2[3]>='A' && s2[3]<='C')
			{
				sc+="1";
			}
			else{
				sc+="0";
			}
			if(s1[3]>='D' && s1[3]<='F' && s2[3]>='D' && s2[3]<='F')
			{
				sc+="1";
			}
			else{
				sc+="0";
			}
		}
	}
	return 0;
}
