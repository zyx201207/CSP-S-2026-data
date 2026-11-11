#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,s,m=0;
	char a1[3],s1[3];
	cin>>a>>a1[0]>>a1[1]>>a1[2]>>s>>s1[0]>>s1[1]>>s1[2];
	if(a==s){
		cout<<"1";
	}else{
		cout<<"0000";
		m=1;
	}
	if(a1[0]==s1[0]&&a1[1]==s1[1]&&m==0){
		cout<<"1";
	}else{
		if(m==0){
			cout<<"000";
		}
		m=1;
	}
	if((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&m==0)
	{
		cout<<"1";
	}else{
		if(((a1[2]=='D'&&s1[2]=='F')||(s1[2]=='D'&&a1[2]=='F'))&&m==0){
			cout<<"1";
		}else{
			if(m==0){
				cout<<"00";
			}
			m=1;
		}
	}
	if(m==0&&a1[2]+s1[2]!='A'+'C')
	{
		cout<<"1"<<endl;
	}else{
		if(m==0){
			cout<<"0"<<endl;
		}
	}
}
