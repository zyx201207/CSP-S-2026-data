#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool a=0,b=0,c=0,d=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		a=1;
	}
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&a){
		cout<<1;
		b=1;
	}
	else cout<<0;
	if(a&&s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))){
		cout<<1;
		c=1;
	}
	else cout<<0;
	if(a&&c&&abs(s1[2]-s2[2])==1)cout<<1;
	else cout<<0;
	return 0;
} 
