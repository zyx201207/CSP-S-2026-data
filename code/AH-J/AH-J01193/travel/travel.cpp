#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string c1,s1,c2,s2;
bool flag=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int lenc=c1.size();
	for(int i=0;i<lenc;i++)
	if(c1[i]!=c2[i]){flag=0;cout<<"0000";}
	if(flag==1)
		if((int(s1[0])-48)*10+int(s1[1])-48!=
		(int(s2[0])-48)*10+int(s2[1])-48){flag=0;cout<<"1000";}
	if(flag==1){
		if(s1[2]=='F')s1[2]='E';
		if(s2[2]=='F')s2[2]='E';
		if((int(s1[2])>=65&&int(s1[2])<=67
		   &&int(s2[2])>=68)||(int(s2[2])>=65&&int(s2[2])<=67
		   &&int(s1[2])>=68)){flag=0;cout<<"1100";}
	}
	if(flag==1){
		if(int(s1[2])-int(s2[2])==1||
		int(s1[2])-int(s2[2])==-1)cout<<"1111";
		else cout<<"1110";
	}
	return 0;
}
