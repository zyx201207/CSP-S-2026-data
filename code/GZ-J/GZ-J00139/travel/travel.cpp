//GZ-J00139 遵义市第十一中学 雷朝典 
#include<bits/stdc++.h>
using namespace std;
int main (){
	int p=0;
	freopen("travel.in","r",stdin);
	freopen("travel.out","o",stdout);
	string s;
	getline(cin,s);
	if(s[0]!=s[7]||s[1]!=s[8]){
		cout<<"0000";
		return 0;
	}
	else if(s[3]!=s[10]||s[4]!=s[11]){
		cout<<"1000";
		return 0;
	}
	else {
		if(s[5]=='F'||s[5]=='D'){
			if(s[12]=='F'||s[12]=='D'){
				p=1;
			}
		}
		else{
			if(s[12]!='F'&&s[12]!='D'){
				p=1;
			}
		}
		if(p==0){
			cout<<"1100";
			return 0;
		}
		else{
			if(s[12]+1==s[5]||s[12]-1==s[5]){
				cout<<"1111";
				return 0;
			}
			else{
				cout<<"1110";
				return 0;
			}
		}
	}
}
