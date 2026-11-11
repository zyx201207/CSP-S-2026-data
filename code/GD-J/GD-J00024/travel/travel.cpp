#include<bits/stdc++.h>
using namespace std;
struct seat{
	int a,b;
	char c;
}s[3];
bool flag1=true,flag2=true,flag3=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
	}
	if(s[1].a==s[2].a){
		cout<<"1";
	}else{
		cout<<"0";
		flag1=false;
	}
	if(s[1].b==s[2].b&&flag1){
		cout<<"1";
	}else{
		cout<<"0";
		flag2=false;
	}
	if(s[1].c>='A'&&s[1].c<='C'&&s[2].c>='A'&&s[2].c<='C'&&flag2){
		cout<<"1";
	}else if(s[1].c>='D'&&s[1].c<='E'&&s[2].c>='D'&&s[2].c<='E'&&flag2){
		cout<<"1";
	}else{
		cout<<"0";
		flag3=false;
	}
	if((s[1].c+1==s[2].c||s[1].c-1==s[2].c)&&flag3){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
