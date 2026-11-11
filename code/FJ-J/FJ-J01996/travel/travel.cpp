#include<bits/stdc++.h>
using namespace std;
char s1[3],s2[3],c1[2],c2[2];
int ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]-'0'==c2[0]-'0'&&c1[1]-'0'==c2[1]-'0'){
		ans[0]=1;
	}
		if(s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'==s2[1]-'0'){
			ans[1]=1;
		}
		
		if(s1[2]-'A'<='C'-'A'&&s2[2]-'A'<='C'-'A'){
			ans[2]=1;
		}
		else if(s1[2]-'A'>'C'-'A'&&s1[2]-'A'<='F'-'A'&&s2[2]-'A'<='F'-'A'&&s2[2]-'A'>'C'-'A'){
			ans[2]=1;
		}
		else{
			cout<<"1100";
			return 0;
		}
		if(s1[2]-'A'=='D'-'A'||s2[2]-'A'=='D'-'A'){
			ans[3]=1;
		}
		else if(s1[2]-'A'-(s2[2]-'A')==1||s2[2]-'A'-(s1[2]-'A')==1){
			ans[3]=1;
		}
		else{
			cout<<"1110";
			return 0;
		}
	cout<<"1111";
	return 0;
	
}
