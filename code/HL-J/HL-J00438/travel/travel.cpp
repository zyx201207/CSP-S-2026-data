#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a,b; 
int f1,f2,f3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    	f1=1;
    	cout<<1;
	}
	else cout<<0;
	if(f1==1){
		if(s1[1]==s2[1]){
			f2=1;
    		cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	if(f2==1){
		if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'){
			f3=1;
    		cout<<1;
		}
		else if(s1[2]<='E'&&s1[2]>='D'&&s2[2]<='E'&&s2[2]>='D'){
    		cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	if(f3==1){
		if(s1[2]-1==s2[2]||s2[2]-1==s1[2]){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
    return 0;
}

