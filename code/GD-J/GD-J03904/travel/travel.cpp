#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,aa,bb;
	cin>>a>>b>>aa>>bb;
	if(a==aa){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a==aa&&b[0]==bb[0]&&b[1]==bb[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	int v=b[2],vv=bb[2];
	if(a==aa&&b[0]==bb[0]&&b[1]==bb[1]&&(b[2]<='C'&&bb[2]<='C'||b[2]>='D'&&bb[2]>='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a==aa&&b[0]==bb[0]&&b[1]==bb[1]&&abs(v-vv)==1&&(b[2]!='C'&&bb[2]!='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
