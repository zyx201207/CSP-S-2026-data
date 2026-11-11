#include<bits/stdc++.h>
using namespace std;
int sum1,sum2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s[5],ans,t1,t2;
	for(int i=1;i<=4;i++){
		cin>>s[i];
	}
	if(s[1]==s[3]){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s[2].length();i++){
		if(isdigit(s[2][i]))
			sum1+=(s[2][i]-'0');
	}
	for(int i=0;i<s[4].length();i++){
		if(isdigit(s[4][i]))
			sum2+=(s[4][i]-'0');
	}
	if(sum1==sum2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	for(int i=1;i<s[2].length();i++)
		if(isalpha(s[2][i]))
			t1+=s[2][i];
	for(int i=0;i<s[4].length();i++)
		if(isalpha(s[4][i]))
			t2+=s[4][i];
	if((t1=="A" && t2=="B") || (t1=="A" && t2=="C") || (t1=="B" && t2=="A") || (t1=="B" && t2=="C") || (t1=="C" && t2=="A") || (t1=="C" && t2=="B") || (t1=="D" && t2=="F") || (t1=="F" && t2=="D")){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if((t1=="A" && t2=="B") || (t1=="B" && t2=="C") || (t1=="D" && t2=="F") || (t1=="B" && t2=="A") || (t1=="C" && t2=="B") || (t1=="F" && t2=="D"))
		cout<<"1";
	else
		cout<<"0";
	return 0;
}
