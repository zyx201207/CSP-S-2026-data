#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool tmp=true;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		tmp=false;
	}
	cout<<(c1==c2);
	if(((s1[0]-'0')*10+s1[1]-'0'!=(s2[0]-'0')*10+s2[1]-'0')){
		tmp=false;
	}
	cout<<(((s1[0]-'0')*10+s1[1]-'0'==(s2[0]-'0')*10+s2[1]-'0')&&tmp);
	if(((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))&&tmp){
		tmp=false;
	}
	cout<<(!((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))&&tmp);
	if(abs(s1[2]-s2[2])!=1){
		tmp=false;
	}
	cout<<tmp;
	return 0;
}
