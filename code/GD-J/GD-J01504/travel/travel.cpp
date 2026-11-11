#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool f1(){
	return a1==b1;
}
bool f2(){
	int pai_a=(a2[0]-'0')*10+a2[1];
	int pai_b=(b2[0]-'0')*10+b2[1];	
	return pai_a==pai_b&&f1();
}
bool f3(){
	bool is_l=(a2[2]>='A'&&a2[2]<='C'&&b2[2]>='A'&&b2[2]<='C');
	bool is_r=((a2[2]=='D'||a2[2]=='F')&&(b2[2]=='D'||b2[2]=='F'));
	return (is_l||is_r)&&f2();
}
bool f4(){
	if(a2[2]=='A'&&b2[2]=='B')return f3();
	if(a2[2]=='B'&&b2[2]=='C')return f3();
	if(a2[2]=='D'&&b2[2]=='F')return f3();
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	char ans[10];
	ans[1]=f1()?'1':'0';
	ans[2]=f2()?'1':'0';
	ans[3]=f3()?'1':'0';
	ans[4]=f4()?'1':'0';
	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
