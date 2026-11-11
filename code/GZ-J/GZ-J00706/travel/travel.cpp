//GZ-J00706 遵义市第十二中学 张明韬
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a,n1,n2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) a=a+"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) a=a+"1";
	else{
		cout<<"1000";
		return 0;
	}
	if(s1[2]>='A' && s1[2]<='C') n1='l';
	else n1='r';
	if(s2[2]>='A' && s2[2]<='C') n2='l';
	else n2='r';
	if(n1==n2) a=a+"1";
	else{
		cout<<"1100";
		return 0;
	}
	if(s1[2]==s2[2]+1 || s1[2]==s2[2]-1) cout<<"1111";
	else cout<<"1110";
	return 0;
} 
