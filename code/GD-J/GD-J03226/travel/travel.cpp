#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char ans[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<4;i++)ans[i]='0';
	
	if(c1==c2)ans[0]='1';//同车厢
	
	if(ans[0]=='0'){
		cout<<ans;
		return 0;
	}
	
	if((s1[0]==s2[0])&&(s1[1]==s2[1]))ans[1]='1';//同一排
	
	if(ans[1]=='0'){
		cout<<ans;
		return 0;
	}
	
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))ans[2]='1';
	else if((ans[1]!='0')&&(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))ans[2]='1';//同一侧 
	
	if(ans[2]=='0'){
		cout<<ans;
		return 0;
	}
	
	if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))ans[3]='1';
	else if((ans[2]!='0')&&(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C'))ans[3]='1';
	else if((ans[2]!='0')&&(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A'))ans[3]='1';//相邻 
	
	if(ans[3]=='0'){
		cout<<ans;
		return 0;
	}
	
	cout<<ans;
	return 0;
}
