#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1,s2;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a>>s1>>c2>>b>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a==b){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
    }
	if((s1<='C'&&s2<='C')||(s1>'C'&&s2>'C')){
		cout<<1;
		if((s1=='A'&&s2=='C')||(s1=='C'&&s2=='A')){
			cout<<0;
		}else{
			cout<<1;
		}
	}else{
		cout<<"00";
	}
	return 0;
}
