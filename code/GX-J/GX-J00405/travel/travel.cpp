#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string c1,s1,c2,s2;
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==s1) cout<<1;
	else cout<<0;
	if(c2[0]==s2[0]&&c2[1]==s2[1]&&c1==s1) cout<<1;
	else cout<<0;
	int h=0;
	if(c2[2]<'C'&&s2[2]<'C') h=1;
	else if(c2[2]>='C'&&s2[2]>='C') h=1;
	if(c2[0]==s2[0]&&c2[1]==s2[1]&&c1==s1&&h==1) cout<<1;
	else cout<<0;
	int a=c2[2],b=s2[2];
	h=0;
	if(c2[2]<'C'&&s2[2]<'C') h=1;
	else if(c2[2]>='C'&&s2[2]>='C'&&max(a,b)-min(a,b)==1) h=1;
	if(h==1) cout<<1;
	else cout<<0;
	return 0;
}
