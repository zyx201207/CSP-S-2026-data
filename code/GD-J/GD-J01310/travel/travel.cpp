#include<bits/stdc++.h>
using namespace std;
bool a,b,c,d;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='F')s1[2]='E';
	if(s2[2]=='F')s2[2]='E';
	if(c1==c2)a=1;
	if(a==1)if(s1[0]==s2[0]&&s1[1]==s2[1])b=1;
	if(b==1){
		if(s1[2]<='C'&&s2[2]<='C')c=1;
		if(s2[2]>='D'&&s2[2]>='D')c=d=1;
	}
	if(c==1)if(abs(s1[2]-s2[2])==1 && ((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))==0)d=1;
	cout<<a<<b<<c<<d<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
