#include<bits/stdc++.h>
using namespace std;
string c="0ABC";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool a1=0,a2=0,a3=0,a4=0; 
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) a1=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&a1) a2=1;
	int t1=0,t2=0;
	for(int i=1;i<=3;i++){
		if(s1[2]==c[i]) t1=1;
		if(s2[2]==c[i]) t2=1;
	} 
	if(t1==t2&&a1&&a2) a3=1;
	if(abs(s1[2]-s2[2])==1&&a1&&a2&&a3) a4=1;
	if(a1) cout<<'1';
	else cout<<'0';
	if(a2) cout<<'1';
	else cout<<'0';
	if(a3) cout<<'1';
	else cout<<'0';
	if(a4) cout<<'1';
	else cout<<'0';
}
