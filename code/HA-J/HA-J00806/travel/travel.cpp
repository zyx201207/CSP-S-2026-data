#include<bits/stdc++.h>
using namespace std;
bool flag=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	int a1=s1[0]*10+s1[1],a2=s2[0]*10+s2[1];
	char ch1=s1[2],ch2=s2[2];
	if(c1==c2){
		cout<<1;
	}else cout<<0;
	if(c1==c2&&a1==a2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&a1==a2&&((ch1<='C'&&ch2<='C')||(ch1>='D'&&ch2>='D'))){
		cout<<1;
		flag=1;
	}else cout<<0;
	if(flag&&((ch1+1==ch2)||(ch1-1==ch2))){
		cout<<1;
	}else cout<<0;
	return 0;
}