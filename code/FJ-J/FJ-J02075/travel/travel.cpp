#include<bits/stdc++.h>
using namespace std;
string s1,s2,a1,a2;
bool flag=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>a1>>s2>>a2;
	if(s1[1]==s2[1]&&s1[0]==s2[0]){
		cout<<'1';
		flag=1;
	}else{
		cout<<'0';
		flag=0;
	}
	if(flag==1&&a1[0]==a2[0]&&a1[1]==a2[1]){
		cout<<'1';
		flag=1;
	}else{
		cout<<'0';
		flag=0;
	}
	if(flag==1&&a1[2]<='C'&&a2[2]<='C'||a1[2]>='D'&&a2[2]>='D'){
		cout<<'1';
		flag=1;
	}else{
		cout<<'0';
		flag=0;
	}
	if(flag==1&&abs(a1[2]-a2[2])==1){
		cout<<'1';
		flag=1;
	}else{
		cout<<'0';
		flag=0;
	}
	return 0;
}
