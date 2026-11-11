#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int flag=0;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(s1.substr(0,2)==s2.substr(0,2) && c1==c2) cout<<1;
	else cout<<0;
	if(s1.substr(0,2)==s2.substr(0,2) && c1==c2 && ((s1.substr(2,1) <="C" && s2.substr(2,1)<="C") or (s1.substr(2,1)>="D" && s2.substr(2,1)>="D"))) cout<<1;
	else cout<<0;
	if(s1.substr(2,1)>="D" && s2.substr(2,1)>="D") flag=1;
	if(flag==1){
		cout<<1;
		return 0;
	}
	else if(s1.substr(0,2)==s2.substr(0,2) && c1==c2 && ((s1.substr(2,1) <="C" && s2.substr(2,1)<="C") or (s1.substr(2,1)>="D"&&s2.substr(2,1)>="D")) && abs(s1[2]-s2[2])==1) cout<<1;
	else cout<<0;
	//cout<<"FLAG"<<flag;
	return 0;
} 
