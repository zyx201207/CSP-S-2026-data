#include<bits/stdc++.h>
using namespace std;
string s,c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
//	cin>>s;
//	for(int i=0;i<=1;i++)c1+=s[i];
//	for(int i=3;i<=5;i++)s1+=s[i];
//	for(int i=7;i<=8;i++)c2+=s[i];
//	for(int i=10;i<=12;i++)s2+=s[i];
	cin>>c1>>s1>>c2>>s2;
//	cout<<c1<<' '<<s1<<' '<<c2<<' '<<s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	char sd1=s1[2],sd2=s2[2];
	int ad1=0,ad2=0;
	for(char i='A';i<='C';i++){
		if(sd1==i)ad1=1;
		if(sd2==i)ad2=1;
	}
	if(ad1!=ad2){
		cout<<"1100";
		return 0;
	}
	if(sd1<='C'&&sd2<='C'){
		if(sd1-sd2==1||sd1-sd2==-1)cout<<"1111";
		else cout<<"1110";
	}else if(sd1>='C'&&sd2>='C'){
		cout<<"1111";
	}else{
		cout<<"1110";
	}
	return 0;
}

