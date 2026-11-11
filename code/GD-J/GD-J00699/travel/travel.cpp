#include<bits/stdc++.h>
#include<string> 
using namespace std;
string c1,s1,c2,s2,ans1,ans2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	ans1='0';
	ans2='1';
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<ans2;
	}
	else
		cout<<ans1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<ans2;
	}
	else
		cout<<ans1;
	if(((s1[2]-'A'>=0&&s1[2]-'A'<3&&s2[2]-'A'>=0&&s2[2]-'A'<3)||(s1[2]-'A'>=3&&s1[2]-'A'<5&&s2[2]-'A'>=3&&s2[2]-'A'<5))&&s1[0]==s2[0]&&s1[1]==s2[1]&&c1[0]==c2[0]&&c1[1]==c2[1])
		cout<<ans2;
	else
		cout<<ans1;
	if(abs(s1[2]-s2[2])==1&&((s1[2]-'A'>=0&&s1[2]-'A'<3&&s2[2]-'A'>=0&&s2[2]-'A'<3)||(s1[2]-'A'>=3&&s1[2]-'A'<5&&s2[2]-'A'>=3&&s2[2]-'A'<5))&&s1[0]==s2[0]&&s1[1]==s2[1]&&c1[0]==c2[0]&&c1[1]==c2[1])
		cout<<ans2;
	else
		cout<<ans1;
	return 0;
}
