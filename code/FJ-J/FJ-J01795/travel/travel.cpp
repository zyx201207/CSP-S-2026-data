#include<bits/stdc++.h>
using namespace std;
long long c1,c2,s1,s2;
char a1,a2;
bool f1,f2,f3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>a1>>c2>>s2>>a2;
	if(c1==c2){
		cout<<1;
		f1=1;
	}
	else cout<<0;
	if(s1==s2&&f1){
		cout<<1;
		f2=1;
	}
	else cout<<0;
	if((a1<='C'&&a2<='C'||a1>='D'&&a2>='D')&&f2){
		cout<<1;
		f3=1;
	}
	else cout<<0;
	if(f3&&abs(a1-a2)==1)cout<<1;
	else cout<<0;
	return 0;
}
