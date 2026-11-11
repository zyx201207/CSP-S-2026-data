//GZ-J00391,安顺市开发区洞口流民族学校,罗俊彦 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	string s,c,ss,cc,ccc,sss;
	cin>>s1>>s2>>c1>>c2;
	s=s[2]++;
	c=c[2]++;
	ss=s[2]--;
	cc=c[2]--;
	ccc=c2[2];
	sss=s2[2];
	if(c1==s1){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	if(s1[0]!=c1[0]||s1[1]!=c1[1]){
		cout<<'0';
	}
	else{
		cout<<'1';
	}
	if((s2[2]!='D'&&c2[2]!='C')&&(s2[2]!='C'||c2[2]!='D')){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	if(cc==sss||c==sss){
	cout << 0;}
	else{	
	cout << 1;}
	return 0;
}
