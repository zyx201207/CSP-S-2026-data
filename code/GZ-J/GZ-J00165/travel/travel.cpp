//GZ-J00165 遵义市第四初级中学 聂宇东
#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a="";
char b1(string c1,string c2){
	for(int i=0;i<=1;i++){
		if(c1[i]!=c2[i]){
			return '0';
		}
	}
	return '1';
}
char b2(string s1,string s2){
	if(a[0]=='0')return '0';
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]){
			return '0';
		}
	}
	return '1';
}
char b3(string s1,string s2){
	if(a[1]=='0')return '0';
	int a=int(s1[2]-'A'),b=int(s2[2]-'A');
	if(a<3 && b<3)return '1';
	else if(a>=3 && b>=3)return '1';
	return '0';
}
char b4(string s1,string s2){
	if(a[2]=='0')return '0';
	int a=int(s1[2]-'A'),b=int(s2[2]-'A');
	if(abs(a-b)==1)return '1';
	return '0';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out ","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	a=a+b1(c1,c2);
	a=a+b2(s1,s2);
	a=a+b3(s1,s2);
	a=a+b4(s1,s2);
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

