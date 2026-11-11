#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int a,b;
	a = (s1[0]-'0')*10 + s1[1] - '0';
	b = (s3[0]-'0')*10 + s3[1] - '0';
	int ans1 = a!=b ? 0 : 1;
	if(ans1==0){
		cout<<"0000";
		return 0;
	}
	cout<<ans1;
	int c = (s2[0]-'0')*10 + s2[1] - '0';
	int d = (s4[0]-'0')*10 + s4[1] - '0';
	int ans2 = c!=d ? 0 : 1;
	if(ans2==0){
		cout<<"000";
		return 0;
	}
	cout<<ans2;
	char e = s2[2],f = s4[2];
	int ans3 = 1;
	if((e<='C'&&f<='C')||(e>='D'||f>='D')){
		ans3 = 1;
	}else
	    ans3 = 0;
	if(ans3==0){
		cout<<"00";
		return 0;
	}
	cout<<ans3;
	if(abs(e-f)==1)
	cout<<1;
	else
	cout<<0;
	return 0;
} 
