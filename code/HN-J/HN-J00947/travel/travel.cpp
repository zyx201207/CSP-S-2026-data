#include<bits/stdc++.h>
using namespace std;
struct q{
	string c,s;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	q a[2];
	for(int i=0;i<2;i++){
		cin>>a[i].c>>a[i].s;
	}
	if(a[0].c==a[1].c){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(a[0].s[0]==a[1].s[0]&&a[0].s[1]==a[1].s[1]){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(a[0].s[2]>='A'&&a[1].s[2]>='A'&&a[0].s[2]<='C'&&a[1].s[2]<='C'||a[0].s[2]>='D'&&a[1].s[2]>='D'&&a[0].s[2]<='F'&&a[1].s[2]<='F'){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		return 0;
	}
	if(a[0].s[2]==a[1].s[2]+1||a[0].s[2]==a[1].s[2]-1){
		cout<<1;
	}
	else{
		
		cout<<0;
	}
	return 0;
} 
