#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char s13,s23;
	cin>>c1>>s1>>s13>>c2>>s2>>s23;
	if(s13=='F'){
		--s13;
		cout<<s13;
	}
	if(s23=='F'){
		--s23;
		cout<<s23;
	}
	int c=(c1==c2),s=(s1==s2),l=((s13==s23-1)||(s13==s23+1)),t=((s13<'D'&&s23<'D')||(s13>'C'&&s23>'C'));
	if(c){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c&&s){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c&&s&&t){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c&&s&&t&&l){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
