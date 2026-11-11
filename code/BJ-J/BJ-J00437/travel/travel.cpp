#include<bits/stdc++.h>
using namespace std;
string p1,q1,p2,q2;
int c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>p1>>q1>>p2>>q2;
	if(p1[0]=='0') c1=p1[1]-'0';
	else c1=10+p1[1]-'0';
	if(p2[0]=='0') c2=p2[1]-'0';
	else c2=10+p2[1]-'0';
	if(q1[0]=='0') s1=q1[1]-'0';
	else s1=10+q1[1]-'0';
	if(q2[0]=='0') s2=q2[1]-'0';
	else s2=10+q2[1]-'0';
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if((q1[2]<='C'&&q2[2]<='C')||(q1[2]>='D'&&q2[2]>='D')){
				cout<<1;
				char a=q1[2],b=q2[2];
				if(a>b) swap(a,b);
				if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F')){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
