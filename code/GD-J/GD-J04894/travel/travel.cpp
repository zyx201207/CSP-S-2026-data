#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool f=0;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')){
		cout<<1;
		f=1;
	}
	else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
		cout<<1;
		f=1;
	}
	else cout<<0;
	if(f&&(s1[2]==(s2[2]+1)||(s1[2]+1)==s2[2])) cout<<1;
	else if(f&&(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')) cout<<1;
	else cout<<0;
//	cout<<(s1[2]==(s2[2]+1)||(s1[2]+1)==s2[2]);
//	cout<<(('A'+1)=='B'? 1:0);
	return 0;
}
//02 03D 02 03F
//02 03A 02 03B
