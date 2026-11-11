#include<bits/stdc++.h>
using namespace std;
int tr(string s){
	return (int(s[0]-'0')*10+int(s[1]-'0'));
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4,ans="";
	cin>>c1>>c2>>c3>>c4;
	int num1=tr(c1);
	int num2=tr(c3);
	ans=ans+char((num1==num2)+'0');
	if(num1==num2&&tr(c2)==tr(c4))ans+='1';
	else ans+='0';
	if(num1==num2&&tr(c2)==tr(c4)){
		int sum=0;
		for(char i='A';i<='C';i++){
			if(c2[2]==i||c4[2]==i)sum++;
		}
		if(sum==2||sum==0)ans+='1';
		else ans+='0';
		if((c2[2]-c4[2]==1||c4[2]-c2[2]==1||(c2[2]=='D'&&c4[2]=='F')||(c2[2]=='F'&&c4[2]=='D'))&&(!(c2[2]=='C'&&c4[2]=='D'||c2[2]=='D'&&c4[2]=='C')))ans+='1';
		else ans+='0';
	}
	else ans+="00";
	cout<<ans;
	return 0;
} 
