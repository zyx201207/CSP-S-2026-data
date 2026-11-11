#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='E')&&(s2[2]>='D'&&s2[2]<='E')))){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='D'&&s2[2]<='E'))||((s1[2]>='D'&&s1[2]<='E')&&(s2[2]>='A'&&s2[2]<='D')))){
		cout<<0<<"\n";
		return 0;
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&((s1[2]>='A'||s1[2]<='C')&&(s2[2]>='A'||s2[2]<='C'))){
		if(s1[2]=='B'||s2[2]=='B'){
			cout<<1<<"\n";
			return 0;
		}else{
			cout<<0<<"\n";
			return 0;
		}
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&((s1[2]>='D'||s1[2]<='E')&&(s2[2]>='D'||s2[2]<='E'))){
		cout<<1<<"\n";
		return 0;
	}else{
		cout<<0<<"\n";
		return 0;
	}
	return 0;
}
