#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ans++;
	else{
		cout<<"0000";
		return 0;
	}
	string pai1="",pai2="";
	for(int i=0;i<=1;i++){
		pai1+=s1[i];
		pai2+=s2[i];
	}
	if(pai1==pai2)ans++;
	else{
		cout<<"1000";
		return 0;
	}
	char ce1=s1[2],ce2=s2[2];
	if((ce1>='A'&&ce1<='C')&&(ce2>='A'&&ce2<='C')){
		ans++;
	}
	else if((ce1>='D'&&ce1<='F')&&(ce2>='D'&&ce2<='F')){
		cout<<"1111";
		return 0;
	}
	else {
		cout<<"1100";
		return 0;
	}
	if(ce1+1==ce2||ce1-1==ce2){
		cout<<"1111";
	}
	else cout<<"1110";
	return 0;
}
