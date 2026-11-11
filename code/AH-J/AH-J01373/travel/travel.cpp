#include<bits/stdc++.h>
using namespace std;
string c[2],s[2];//C che xiang,S zuo wei,

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i;
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	int num[4];
	if(c[1]!=c[2])
	cout<<"0000";
	else cout<<"1";
	for(i=1;i<=2;i++)
	{
		if(s[i]=="01A"){
			num[2*i-1]=1;num[2*i]=1;}
		else if(s[i]=="02A"){
			num[2*i-1]=2;num[2*i]=1;}
		else if(s[i]=="03A"){
			num[2*i-1]=3;num[2*i]=1;}
		else if(s[i]=="04A"){
			num[2*i-1]=4;num[2*i]=1;}
		else if(s[i]=="05A"){
			num[2*i-1]=5;num[2*i]=1;}
		else if(s[i]=="06A"){
			num[2*i-1]=6;num[2*i]=1;}
		else if(s[i]=="07A"){
			num[2*i-1]=7;num[2*i]=1;}
		else if(s[i]=="08A"){
			num[2*i-1]=8;num[2*i]=1;}
		else if(s[i]=="09A"){
			num[2*i-1]=9;num[2*i]=1;}
		else if(s[i]=="10A"){
			num[2*i-1]=10;num[2*i]=1;}
		else if(s[i]=="11A"){
			num[2*i-1]=11;num[2*i]=1;}
		else if(s[i]=="12A"){
			num[2*i-1]=12;num[2*i]=1;}
		else if(s[i]=="13A"){
			num[2*i-1]=13;}
		else if(s[i]=="14A"){
			num[2*i-1]=14;}
		else if(s[i]=="15A"){
			num[2*i-1]=15;}
		else if(s[i]=="16A"){
			num[2*i-1]=16;}
		else if(s[i]=="17A"){
			num[2*i-1]=17;}
		else if(s[i]=="18A"){//shuzi jieshu
			num[2*i-1]=18}
		}
		if(num[1]==num[3])
		{
		cout<<"11";
		}
		else cout<<"01";
	return 0;
}
