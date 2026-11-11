#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string ok="";
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int n1,n2;
	char ch1=s1[2],ch2=s2[2];
	n1+=(s1[1]-'0')+(s1[0]-'0')*10;
	n2+=(s2[1]-'0')+(s1[0]-'0')*10;
	if(c1==c2){
		ok+='1';
		if(n1==n2)
		{
			ok+='1';
			if((ch1>='A'&&ch1<='C'&&ch2>='A'&&ch2<='C')||((ch1=='D'||ch1=='F')&&(ch2=='D'||ch2=='F')))
			{
				ok+='1';
				if(abs(ch2-ch1)==1)
				{
					ok+='1'; 
				}
				else ok+='0';
			}
			else ok+="00";
		}
		else ok+="000";
	}
	else{
		cout<<"0000";
	}
	cout<<ok;
	return 0;
}
