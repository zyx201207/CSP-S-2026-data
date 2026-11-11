#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
char s,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>s>>b>>d>>t;
	if(a==b){
		cout<<1;
		if(c==d){
			cout<<1;
			if((s>='A'&&s<='C')&&(t<='E'&&t>='D')){
				cout<<0<<0;
			}else if((t>='A'&&t<='C')&&(s<='E'&&s>='D')){
				cout<<0<<0;
			}else{
				cout<<1;
				if(abs(s-t)==1){
					cout<<1;	
				}else{
					cout<<0;
				}
			}
		}else{
			cout<<0<<0<<0;	
		}
	}else{
		cout<<0<<0<<0<<0;
	}
    return 0;
}
