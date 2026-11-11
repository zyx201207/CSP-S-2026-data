#include<bits/stdc++.h>
using namespace std;
bool cmp(string s1,string s2){
	if((s1[2]=='F'||s1[2]=='D')&&(s2[2]=='F'||s2[2]=='D')) return true;
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')) return true;
    return false;	
}
bool cmp1(string s1,string s2){
	if((s1[2]=='A'&&s1[2]=='B')||(s1[2]=='B'&&s1[2]=='A')||(s1[2]=='B'&&s1[2]=='C')||(s1[2]=='C'&&s1[2]=='B')) return true;
	if((s1[2]=='F'||s1[2]=='D')&&(s2[2]=='F'||s2[2]=='D')) return true;
	return false;
	
}
bool cm(string s1,string s2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]) return true;
		return false;
}
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<1;
		if(cm(s1,s2)){
			cout<<1;
			if(cmp(s1,s2)){
				cout<<1;
				if(cmp1(s1,s2)){
					cout<<1;
				}else{
					cout<<"0";
					return 0;
				}
			}else if(!cmp(s1,s2)){
				cout<<"00";
				return 0;
			}
		}else if(!cm(s1,s2)){
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
	return 0;
	}
	fclose(stdin);
	fclose(stdout);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
	return 0;
} 


