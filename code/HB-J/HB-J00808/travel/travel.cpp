#include<bits/stdc++.h>
using namespace std;
char c;
char s1,s2;
int a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>c>>b1>>s1>>c>>a2>>c>>b2>>s2;
	bool flag1=1,flag2=1,flag3=1;
	if(a1==a2) cout<<1;
	else{
		cout<<0;
		flag1=0;
	}
	if(b1==b2&&flag1) cout<<1;
	else{
		cout<<0;
		flag2=0;
	}
	if(((s1<='C'&&s2<='C')||(s1>='D'&&s2>='D'))&&flag2) cout<<1;
	else{
		cout<<0;
		flag3=0;
	}
	if((s1+1==s2||s1-1==s2||(s1=='D'&&s2=='F')||(s1=='F'&&s2=='D')&&flag3) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
