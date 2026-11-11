#include<bits/stdc++.h>
using namespace std;
string c,s,c1,s1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	if(c==c1){
		cout<<"1";
		if(s[0]==s1[0]&&s[1]==s1[1]){
			cout<<"1";
			if((s[2]<='C'&&s[2]>='A'&&s1[2]<='C'&&s1[2]>='A')||(s[2]<='E'&&s[2]>='D'&&s1[2]<='E'&&s1[2]>='D')){
				cout<<"1";
				if((s[2]+1==s1[2]||s[2]-1==s1[2])&&s[2]+1!='D'&&s[2]-1!='C')cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}  
