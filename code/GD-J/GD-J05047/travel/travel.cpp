#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1,c1;
	string s2,c2;
	int a=0,b=0,c=0,d=0;
	cin>>s1>>c1>>s2>>c2;
//	cout<<s1<<" "<<c1<<" "<<s2<<" "<<c2<<"\n";
	if(s1==s2){
		a=1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(c1[1]==c2[1]&&c1[0]==c2[0]){
		b=1;
	}
	else{
		cout<<"1000";
		return 0;
	}
	if(c1[2]=='D'&&c2[2]=='F'||c1[2]=='F'&&c2[2]=='D'||c1[2]=='A'&&c2[2]=='B'||c1[2]=='A'&&c2[2]=='C'||c1[2]=='B'&&c2[2]=='A'||c1[2]=='C'&&c2[2]=='A'||c1[2]=='B'&&c2[2]=='C'||c1[2]=='C'&&c2[2]=='B'){
		c=1;
	}
	else{
		cout<<"1100";
		return 0;
	}
	if(c1[2]=='A'&&c2[2]=='B'||c1[2]=='D'&&c2[2]=='F'||c1[2]=='F'&&c2[2]=='D'||c1[2]=='B'&&c2[2]=='A'||c1[2]=='B'&&c2[2]=='C'||c1[2]=='C'&&c2[2]=='B'){
		d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
