#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("travel5.in","r",stdin);
	freopen("travel5.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	string s1_l="";
	char s1_r;
	string s2_l="";
	char s2_r;
	
	if(c1!=c2) cout<<"0000"<<endl;
	else{
		for(char c:s1){
			if(c>='0'&&c<='9') s1_l+=c;
			else s1_r=c; 
		}
		for(char c:s2){
			if(c>='0'&&c<='9') s2_l+=c;
			else s2_r=c; 
		}
		if(s1_l!=s2_l) cout<<"1000"<<endl;
		else{
			if(s1_r=='D'&&s2_r=='F'||s2_r=='D'&&s1_r=='F') cout<<"1111"<<endl;
			else if(s1_r=='D'&&s2_r!='F'||s2_r=='D'&&s1_r!='F') cout<<"1100"<<endl;
			else{
				if((int)s1_r-s2_r==1||(int)s1_r-s2_r==-1) cout<<"1111"<<endl;
				else cout<<"1110"<<endl; 
			}
		}
	}
	 
	return 0;
}


