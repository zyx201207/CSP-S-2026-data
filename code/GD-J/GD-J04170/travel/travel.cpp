#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans="0000";
int k1,k2;
char num1,num2;
int main(){	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		for(int i=0;i<4;i++){
			cout<<ans[i];
		}
		return 0;
	}else{
		ans[0]='1';
	}
	
	for(int i=0;i<s1.size();i++){
		if(!('A'<=s1[i] && s1[i]<='Z')){
			k1*=10;
			k1+=s1[i]-'0';
		}else{
			num1=s1[i];
		}
	}
	for(int i=0;i<s2.size();i++){
		if(!('A'<=s2[i] && s2[i]<='Z')){
			k2*=10;
			k2+=s2[i]-'0';
		}else{
			num2=s2[i];
		}
	}
	if(k1==k2){
		ans[1]='1';
	}else{
		for(int i=0;i<4;i++){
			cout<<ans[i];
		}
		return 0;
	}
	if(('A'<=num1 && num1<='C')&&(('A'<=num2 && num2<='C')) || 
	   ('D'<=num1 && num1<='E')&&(('D'<=num2 && num2<='E'))){
		ans[2]='1';
	}else{
		for(int i=0;i<4;i++){
			cout<<ans[i];
		}
		return 0;
	}
	if(abs(num1-num2)==1){
		ans[3]='1';
	}
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	return 0;
}
