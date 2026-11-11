#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char ch,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>ch>>b>>d>>s;
	if((a==b)){
		cout<<1;
	}else {
		cout<<0;	
	}
	if((c==d)&&a==b){
		cout<<1;
	}else{
		cout<<0;
	}
	if((c==d&&(char(ch+1)==s||char(ch+2)==s||char(s+1)==ch||char(s+2)==ch)&&!(ch=='C'&&s=='D'||ch=='D'&&s=='C'))){
		cout<<1;
	}else{
		cout<<0;
	}
	if((c==d&&(char(ch+1)==s||char(s+1)==ch)&&!(ch=='C'&&s=='D'||ch=='D'&&s=='C'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
