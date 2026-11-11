#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,t1,t2;
int f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		f=1;
		cout<<0;
	}
	t1+=s1[0]+s1[1];
	t2+=s2[0]+s2[1];
	if(t1==t2){
		if(f){
			cout<<0;
		}else{
			cout<<1;
		}
	}else{
		cout<<0;
		f=1;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
		if(f){
			cout<<0;
		}else{
			cout<<1;
		}
	}else{
		cout<<0;
		f=1;
	}
	if(abs(s1[2]-s2[2])==1&&f==0){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

