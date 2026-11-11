#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2,s5,s6;
	char s3,s4;
	cin>>c1>>s1>>s3>>c2>>s2>>s4;
	//s5='3['
	//s6='s4';
	if(c1==c2)
	{
		cout<<"1";
	}else
	{
		cout<<"0000";
		return 0;
	}
	if(s1==s2)
	{
		cout<<"1";
	}else
	{
		cout<<"000";
		return 0;
	}
	if(s3=='A'&&s4=='B')
	{
		cout<<"11";
		return 0;
	}else if(s3=='A'&&s4=='C')
	{
		cout<<"10";
		return 0;
	}else if(s3=='B'&&s4=='C')
	{
		cout<<"11";
		return 0;
	}else if(s3=='B'&&s4=='A')
	{
		cout<<"11";
		return 0;
	}else if(s3=='C'&&s4=='B')
	{
		cout<<"11";
		return 0;
	}else if(s3=='C'&&s4=='A')
	{
		cout<<"10";
		return 0;
	}else if(s3=='D'&&s4=='E')
	{
		cout<<"11";
		return 0;
	}else if(s3=='E'&&s4=='D')
	{
		cout<<"11";
		return 0;
	}else
	{
		cout<<"00";
	}
	//if(s5>=A||s6<=29493)cout<<"10"<<endl;
	/*if(s5+1==s6||s5+1==s6||s5+1==s6||s5+1==s6)
	{
		cout<<"1";
	}else
	{
		cout<<"000";
		return 0;
	}*/
	//cout<<c1<<" "<<s1<<" "<<s3<<" "<<s5<<" "<<c2<<" "<<s2<<" "<<s4<<" "<<s6;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
