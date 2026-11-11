#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in ","r",stdin);
	freopen("travel.out ","w",stdout);
	int a1;
	char s[10];
	int a2;
	char x[10];
	cin>>a1>>a2;
	for(int i=1;i<=3;i++){
		cin>>s[i];
	}
	for(int i=1;i<=3;i++){
		cin>>x[i];
	}
	if(a1==a2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s[1]==x[1]&&s[2]==x[2]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s[3]+1==x[3]||s[3]+2==x[3]||s[3]-1==x[3]||s[3]-2==x[3]&&s[3]!='D'&&s[3]!='C'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((s[3]+1==x[3]||s[3]-1==x[3])&&(x[3]!='D'||s[3]!='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
