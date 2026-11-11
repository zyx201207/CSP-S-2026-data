#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int c1,c2;
	bool f1=0,f2=0,f3=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		f1=1;
	}
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&f1==1){
		cout<<1;
		f2=1;
	}
	else cout<<0;
	if(f1==1&&f2==1&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))){
		cout<<1;
		f3=1;
	}
	else cout<<0;
	if(f1==1&&f2==1&&f3==1&&abs((int)s1[2]-(int)s2[2])==1)cout<<1;
	else cout<<0;
	return 0;
}

