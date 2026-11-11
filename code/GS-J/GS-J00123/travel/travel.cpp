#include<iostream>
#include<cstdio>
#include<cstring>
int main{
freopen(" travel.in","r",stdin);
freopen(" travel.out","w",stdout);
int c1,c2;
cin>>c1>>c2;
int s1[2],s2[2];
cin>>s1[2]>>s2[2];
if(c1==c2&&c1!=01&&c1!=16){
	cout<<1;
	if(s1[0]==s2[0]){
		cout<<1;
		if(s1[1]=="D"&&s2[1]=="F"||s1[1]=="F"&&s2[1]=="D")cout<<11;
		else if(s1[1]=="A"&&s2[1]=="B"||s1[1]=="B"&&s2[1]=="C")cout<<11;
		else if(s1[1]=="C"&&s2[1]=="D"||s1[1]=="D"&&s2[1]=="C")cout<<10;
		else cout<<00;
	}
	else cout<<1000;
}
else cout<<0000;



return 0;
}
