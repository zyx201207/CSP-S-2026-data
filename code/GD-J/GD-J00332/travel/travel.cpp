#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define endl "\n"
signed main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=0,b=0,x=0,y=0; 
	for(int i=0;i<c1.size();i++){
		a=a*10+(c1[i]-'0');
	}
	for(int i=0;i<c2.size();i++){
		b=b*10+(c2[i]-'0');
	}
	for(int i=0;i<s1.size()-1;i++){
		x=x*10+(s1[i]-'0');
	}
	for(int i=0;i<s2.size()-1;i++){
		y=y*10+(s2[i]-'0');
	}
	if(a==1||a==16||b==1||b==16) return 0;
	if(a==b) cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	if(x==y) cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]>='D')) cout<<"1";
	else {
		cout<<"00";
		return 0;
	}
	if(s1[2]>='D'&&s2[2]>='D') cout<<"1";
	else if(s1[2]<='C'&&s2[2]<='C'&&((s1[2]-'A')==(s2[2]-'A')+1||(s1[2]-'A')==(s2[2]-'A')-1)) cout<<"1";
	else cout<<"0";
	return 0;
}
