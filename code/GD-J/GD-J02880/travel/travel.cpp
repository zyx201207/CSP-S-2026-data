#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel5.out","w",stdout);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s2[1]!=s1[1]){
		cout<<"1000";
		return 0;
	}
	int a=s1[2]-'A'+1,b=s2[2]-'A'+1;
	int l1,l2;
	if(1<=a&&a<=3)l1=1;
	else l1=2;
	if(1<=b&&b<=3)l2=1;
	else l2=2;
	if(l1!=l2){
		cout<<"1100";
		return 0;
	}
	if(abs(a-b)==1)cout<<"1111";
	else cout<<"1110";
	return 0;
}
