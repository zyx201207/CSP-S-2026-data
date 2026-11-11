#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	int a=(int(s1[0])-48)*10+int(s1[1])-48;
	int b=(int(s2[0])-48)*10+int(s2[1])-48;
	if(a==b) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((int(s1[2])<=int('C')&&int(s2[2])<=int('C'))||(int(s1[2])>int('C')&&int(s2[2])>int('C'))) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(int(s1[2])>=int('D'))s1[2]+=1;
	if(int(s2[2])>=int('D'))s2[2]+=1;
	if(int(s1[2])+1==int(s2[2])||int(s2[2])+1==s1[2]) cout<<"1";
	else cout<<"0";
}
