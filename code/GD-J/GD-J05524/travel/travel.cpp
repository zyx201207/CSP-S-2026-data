#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	string s1,s2;
	cin>>x>>s1>>y>>s2;
	if(x!=y){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A')||(s1[2]>='D'&&s2[2]<='E'&&s1[2]<='E'&&s2[2]>='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	char c1=s1[2],c2=s2[2];
	if(abs(c1-c2)<=1){
		cout<<1;
	}else{
		cout<<0;
	}
} 
