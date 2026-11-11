#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string s;
string sb(string a,string b){
	if(a=="A"&&b=="B"){
		s+="1";
		return s;
	}else if(a=="B"&&(b=="A"||b=="C")){
		s+="1";
		return s;
	}else if(a=="C"&&(b=="B")){
		s+="1";
		return s;
	}else if(a=="D"&&(b=="F")){
		s+="1";
		return s;
	}else if(a=="F"&&(b=="D")){
		s+="1";
		return s;
	}
	s+="0";
	return s;
}
int main(){
    
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		s+="1";
	}else{
		cout<<"0000";
		return 0;
	}
	
	
	for(int i=1;i<=2;i++){
		if(i==1){
			string a,b;
			a=s1[i]+s1[i-1];
			b=s2[i]+s2[i-1];
			if(a==b){
				s+="1";
			}else{
				s+="0";
			}
		}else{
			string a,b;
			a=s1[i];
			b=s2[i];
			if((a=="A"||a=="B"||a=="C")&&(b=="A"||b=="B"||b=="C")){
				s+="1";
			}else if((a=="D"||a=="F")&&(b=="D"||a=="F")){
				s+="1";
			}else{
				s+="0";
			}
			s=sb(a,b);
		}
	}
	
	
	cout<<s<<endl;
	return 0;
}
