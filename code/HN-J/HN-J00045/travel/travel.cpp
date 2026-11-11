#include<bits/stdc++.h>
using namespace std;
//02 02B 12 01A 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else cout<<1;
	
	int x=s1[0]-'0'+s1[1]-'0';
	int y=s2[0]-'0'+s2[1]-'0';
	
	if(x==y)cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	
	char ch1=s1[2];
	char ch2=s2[2];
	
	if(ch1>='D'&& ch2>='D'){
		cout<<11;
	}
	else if(ch1>='A'&& ch1<='C'&& ch2>='A'&& ch2<='C'){
		cout<<1;
		x=s1[2]-'0';
		y=s2[2]-'0';
		if(abs(x-y)==1){
			cout<<1;
			return 0;	
		}
	}
	else cout<<0;
	cout<<0;
	
	return 0;
}
