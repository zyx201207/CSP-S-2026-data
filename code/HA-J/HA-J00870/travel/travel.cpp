#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool b1,b2,b3;
	cin>>c1>>s1>>c2>>s2;
	b1=b2=b3=0;
	if(c1==c2){
		cout<<1;
		b1=1;
	}
	else cout<<0;
	if(b1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		b2=1;
	}
	else cout<<0;
	if(b2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))){
		cout<<1;
		b3=1;
	}
	else cout<<0;
	if(b3&&abs(s1[2]-s2[2])==1) cout<<1;
	else cout<<0;
	return 0;
}

