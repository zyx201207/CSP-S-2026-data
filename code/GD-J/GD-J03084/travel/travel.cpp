#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travle.out","w",stdout);
	string a1,s1,a2,s2;
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	string d1=s1.substr(0,2),d2=s2.substr(0,2);
	if(d1==d2)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char c1=s1[2],c2=s2[2];
	if((c1<'D'&&c2<'D')||(c1>'C'&&c2>'C'))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(c2-c1==1||c1-c2==1||(c1=='D'&&c2=='F')||(c1=='F'&&c2=='D'))cout<<1;
	else cout<<0;
	return 0;
} 
