#include<bits/stdc++.h>
using namespace std;
int a1,s1;
string a,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a>>s1>>s;
	if(a1==s1)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(a[0]==s[0]&&a[1]==s[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(a[2]>='A'&&a[2]<='C'&&s[2]>='A'&&s[2]<='C'||a[2]>='D'&&a[2]<='F'&&s[2]>='D'&&s[2]<='F')cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(a[2]-s[2]==1&&a[2]!='D'&&s[2]!='C'||s[2]-a[2]==1&&s[2]!='D'&&a[2]!='C')cout<<1;
	else cout<<0;
	return 0; 
} 
