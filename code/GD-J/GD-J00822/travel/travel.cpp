#include<bits/stdc++.h>
using namespace std;
int a,a1,b,b1;
char aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>aa>>b>>b1>>bb;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(a1!=b1){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(aa<='C'&&aa>='A')a=1;
	else a=2;
	if(bb<='C'&&bb>='A')b=1;
	else b=2;
	if(a!=b){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(aa=='A'&&bb=='C'||aa=='C'&&bb=='A')cout<<"0";
	else cout<<"1";
	return 0;
}
