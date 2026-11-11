#include<bits/stdc++.h>
using  namespace std;
string c1,s1,c2,s2;
bool flag1=0,flag2=0,flag3=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		flag1=1;
	}else{
		cout<<"0";
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
		flag2=1;
	}else{
		cout<<"0";
	}
	int a1=int(s1[2]-'0');
	int a2=int(s2[2]-'0');
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(abs(a1-a2)==1||abs(a1-a2==2))&&!((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D'))&&!((s1[2]=='F'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='F'))&&!(s1[2]=='D'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='D')){
		cout<<"1";
		flag3=1;
	}else{
		cout<<"0";
	}
	if(flag1&&flag2&&flag3&&abs(a1-a2)==1){
		cout<<"1";
	}else{
		cout<<"0";	
	}
	return 0;
}
