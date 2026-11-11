#include<bits/stdc++.h>
using namespace std;
int n,c1,c2,a,b,c,d;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}
	a++;
	int t1=s1[0]*10+s1[1],t2=s2[0]*10+s2[1];
	if(t1!=t2){
		cout<<"1000"<<endl;
		return 0;
	}
	b++;
	if((s2[2]=='C'&&s1[2]=='D')||(s1[2]=='C'&&s2[2]=='D')){
		cout<<"1100"<<endl;
		return 0;
	}
	else if((s2[2]=='B'&&s1[2]=='D')||(s1[2]=='B'&&s2[2]=='D')){
		cout<<"1100"<<endl;
		return 0;
	}
	else if((s2[2]=='A'&&s1[2]=='D')||(s1[2]=='A'&&s2[2]=='D')){
		cout<<"1100"<<endl;
		return 0;
	}
	else if((s2[2]=='C'&&s1[2]=='F')||(s1[2]=='C'&&s2[2]=='F')){
		cout<<"1100"<<endl;
		return 0;
	}
	else if((s2[2]=='B'&&s1[2]=='F')||(s1[2]=='B'&&s2[2]=='F')){
		cout<<"1100"<<endl;
		return 0;
	}
	else if((s2[2]=='A'&&s1[2]=='F')||(s1[2]=='A'&&s2[2]=='F')){
		cout<<"1100"<<endl;
		return 0;
	}
	c++;
	if((s1[2]=='A'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='C')){
		cout<<"1110"<<endl;
		return 0; 
	}
	d++;
	if(abs(s1[2]-s2[2])==1){
		cout<<"1111"<<endl;
		return 0;
	}
	return 0;
}
