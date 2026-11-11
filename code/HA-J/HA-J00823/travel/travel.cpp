#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,num1,num2,word1,word2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			num1+=s1[i];
		}else{
			word1+=s1[i];
		}
		if(s2[i]>='0'&&s2[i]<='9'){
			num2+=s2[i];
		}else{
			word2+=s2[i]; 
		}
	}
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}if(num1==num2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((word1!="F"&&word1!="D"&&word2!="F"&&word2!="D")||(word1!="A"&&word1!="B"&&word1!="C"&&word2!="A"&&word2!="B"&&word2!="C")){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}if((word1=="A"&&word2=="B"||word2=="A"&&word1=="B")||(word1=="B"&&word2=="C"||word2=="B"&&word1=="C")||(word1=="D"&&word2=="F"||word2=="D"&&word1=="F")){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

