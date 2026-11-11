#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
string num1,num2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	num1=s1[0];
	num2=s2[0];
	num1+=s1[1];
	num2+=s2[1];
	bool flag=(c1==c2&&num1==num2);
	if(s1[2]=='C'&&s2[2]=='D') flag=0;
	if(s1[2]=='D'&&s2[2]=='C') flag=0;
	bool is_near=0;
	if((s1[2]+1==s2[2] || s2[2]+1==s1[2])&&flag) is_near=1;
	//cout<<num1<<' '<<num2;
	cout<<(c1==c2)<<(c1==c2&&num1==num2);
	cout<<flag<<is_near;
	//cout<<s1[2]<<' '<<s2[2];
	//cout<<(s1[2]+1==s2[2]);
	
	return 0;
}
