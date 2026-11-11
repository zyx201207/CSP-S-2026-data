#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) s+="1";
	else{
		s+="0000";
		cout<<s;
		return 0;
	}
	bool f=1;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]) f=0;
	}
	if(f) s+="1";
	else{
		s+="000";
		cout<<s;
		return 0;
	} 
	if(s1[2]>=65&&s1[2]<=67){
		if(s2[2]>=65&&s2[2]<=67) s+="1";
		else{
			s+="00";
			cout<<s;
			return 0;
		}
	}
	else{
		if(s2[2]>67) s+="1";
		else{
			s+="00";
			cout<<s;
			return 0;
		} 
	}
	if(s1[2]+1==s2[2]) s+="1";
	else if(s1[2]-1==s2[2]) s+="1";
	else if(s1[2]>67) s+="1";
	else{
		s+="0";
		cout<<s;
		return 0;
	}
	cout<<s;
	return 0;
}
