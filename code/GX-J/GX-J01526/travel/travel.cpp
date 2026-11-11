#include<bits/stdc++.h>
using namespace std;
string s11,s22;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		for(int i=0;i<s1.size();i++){
			if(s1[i]>='0'&&s1[i]<='9'){
				s11+=s1[i];
			}
		}
		for(int i=0;i<s2.size();i++){
			if(s2[i]>='0'&&s2[i]<='9'){
				s22+=s2[i];
			}
		}
		if(s11==s22){
			cout<<"1";
			char a,b;
			a=s1[s1.size()-1];
			b=s2[s2.size()-1];
			if((a<='C'&&a>='A')&&(b<='C'&&b>='A')){
				cout<<"1";
				if(max(a,b)-min(a,b)==1)cout<<"1";
				else cout<<"0";
			}
			else{
				if((a=='D'||a=='F')&&(b=='D'||b=='F'))cout<<"11";
				else cout<<"00";
			} 
		}
		else cout<<"000";
		
	}
	else cout<<"0000";
	
	return 0;
}
