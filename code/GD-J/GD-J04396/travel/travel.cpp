#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int f,fl,fla,flag;
int main(){	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc) f=1;
	if(s[0]==ss[0]&&s[1]==ss[1]&&f==1) fl=1;
	if(fl==1){
		if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(ss[2]=='A'||ss[2]=='B'||ss[2]=='C')&&(s[2]!=ss[2])) fla=1;
		else{
			if((s[2]=='D'||s[2]=='F')&&(ss[2]=='D'||ss[2]=='F')&&(s[2]!=ss[2])) fla=1;
		}
	}
	if(fla==1){
		if((s[2]=='D'&&ss[2]=='F')||(s[2]=='F'&&ss[2]=='D')&&(s[2]!='C'&&ss[2]!='C')&&(s[2]!='B'&&ss[2]!='B')&&(s[2]!='A'&&ss[2]!='A')) flag=1;
		else if((s[2]+1==ss[2]||s[2]-1==ss[2])&&(s[2]!='D'&&s[2]!='F'&&ss[2]!='D'&&ss[2]!='F')) flag=1;
	}
	cout<<f<<fl<<fla<<flag;
	return 0;
}


