#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c[5];
	int s[5];
	for(int i=1;i<=2;i++){
		cin>>c[i]>>s[i];	
	}
	if(c[1]==c[2]){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s[1]-s[2]<=5||s[2]-s[1]<=5)cout <<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s[2]<='c'&&s[1]<='c'||s[2]>='d'&&s[1]>='d') cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(s[1]-s[2]==1||s[2]-s[1]==1)cout<<1;
	else cout<<0;
	return 0;
} 
