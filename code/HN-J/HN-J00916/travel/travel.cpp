#include<bits/stdc++.h> 
using namespace std;
int main(){
	string s1,s2,s3,s4,temp,s;
	bool a=false,b=false,c=false,d=false;
//	cin>>s1>>s2>>s3>>s4;
	ifstream inf("travel.in");
	ofstream outf("travel.out");
	while(inf>>temp){
		s+=temp;
	}
	int num=0;
	for(int i=0;i<s.length();i++){
		if(s[i]!=' '&&num==0){
			s1[i]=s[i];
		}else if(s[i]!=' '&&num==1){
			s2[i-3]=s[i];
		}else if(s[i]!=' '&&num==1){
			s3[i-7]=s[i];
		}else if(s[i]!=' '&&num==1){
			s4[i-10]=s[i];
		}else{
			num++;
		}
		
		
	}
	if(s1[0]==s3[0]&&s1[1]==s3[1]){
		a=true;
			if(s2[1]==s4[1]&&s2[0]==s4[0]){
				b=true;
				if(s2[1]==s4[1]&&(!(s2[2]=='D'&&s4[2]==s2[2]-1)&&!(s2[2]=='C'&&s4[2]==s2[2]+1))){
					c=true;
					if(s2[2]+1==s4[2]||s2[2]==s4[2]+1){
						d=true;
					}
				}
			}
	}
	outf<<a<<b<<c<<d;
	return 0;
}
