#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen(".in","r",stdin);
	freopen(".in","w",stdout);
	int c1;
	cin >>c1;
	string s1;
	cin >>s1;
	int c2;
	cin>>c2;
	string s2;
	cin>>s2;
	if(c1==c2)
		cout<<"1";
	else
		cout<<"0";
	int a,b;
	if(s1[2]=='A')
		a=1;
	else if(s1[2]=='B')
		a=2;
	else if(s1[2]=='C')
		a=3;
	else if(s1[2]=='D')
		a=4;
	else if(s1[2]=='E')
		a=5;
	if(s2[2]=='A')
		b=1;
	else if(s2[2]=='B')
		b=2;
	else if(s2[2]=='C')
		b=3;
	else if(s2[2]=='D')
		b=4;
	else if(s2[2]=='E')
		b=5;
	if((c1==c2)&&((s1[0]==s2[0])&&(s1[1]==s2[1]))){
		cout<<"1";
		
	}else
		cout<<"0";
	if((c1==c2)&&((s1[0]==s2[0])&&(s1[1]==s2[1]))&&((a<=3&&b<=3)||(a>3&&b>3))){
			cout<<"1";
			
		}else
			cout<<"0";
	if((c1==c2)&&((s1[0]==s2[0])&&(s1[1]==s2[1]))&&((a<=3&&b<=3)||(a>3&&b>3))&&((a-b==1)||(b-a==1)))
			cout<<"1";
	else
			cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
