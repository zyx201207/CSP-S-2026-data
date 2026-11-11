#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int c1,c2,s1,s2,t=0;
    char n,m;
    cin>>c1>>n;
    s1=n-'0';
    cin>>n;
    s1=s1*10+n-'0';
    cin>>n;
    cin>>c2>>m;
    s2=m-'0';
    cin>>m;
    s2=s2*10+m-'0';
    cin>>m;
    if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
		t=1;
	}
	if(s1==s2&&t==0){
		cout<<1;
	}else{
		cout<<0;
		t=1;
	}
	if(((n<='C'&&n>='A'&&m<='C'&&m>='A')||(n>='D'&&n<='F'&&m>='D'&&m<='F'))&&(t==0)){
		cout<<1;
	}else{
		cout<<0;
		t=1;
	}
	if(n<='C'&&n>='A'&&m<='C'&&m>='A'){
		if((n-1==m||m-1==n)&&t==0){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		if(t==0){
			cout<<1;
		}else{
			cout<<0;
		}
		
	}
    return 0;
}
