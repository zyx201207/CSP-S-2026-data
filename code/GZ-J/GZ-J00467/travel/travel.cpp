//GZ-J00467 贵阳市第十八中学 曹文坤
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<'0';
	}
	else{
		cout<<'1';
	}
	if(s1[1]==s2[1]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if((s1[1]==s2[1]) && ((s1[2]<='C' && s2[2]<='C') || s1[2]>='D' && s2[2]>='D')){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(((s1[2]<='C' && s2[2]<='C')||(s1[2]>='D' && s2[2]>='D')) && ((s1[1]==s2[1] && ((s1[2]+1==s2[2] || s1[2]+3==s2[2]) || (s2[2]+1==s1[2] ||s2[2]+3==s1[2])))) && c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
	
} 
