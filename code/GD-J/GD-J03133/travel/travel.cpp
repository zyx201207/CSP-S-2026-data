#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	char ans[5]={};
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[1]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[2]='1';
			if('A'<=s1[2]<='C'&&'A'<=s2[2]<='C'){
				ans[3]='1';
				if(s1[2]=='B'||s2[2]=='B'){
					ans[4]='1';
				}
				else ans[4]='0';
			}
			else if('D'<=s1[2]<='F'&&'D'<=s2[2]<='F'){
				ans[3]='1';
				ans[4]='1';
			}
			else{
			ans[3]='0';
			ans[4]='0';
		}
			
		}
		else{
			ans[2]='0';
			ans[3]='0';
			ans[4]='0';
		}
		
	}
	else {
		cout<<'0'<<'0'<<'0'<<'0';
		return 0;
	}
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
} 
