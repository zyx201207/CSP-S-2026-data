#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
bool f=1;
string tmp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>tmp;
	c1=(tmp[0]-'0')*10+(tmp[1]-'0')*1;
	cin>>tmp;
	s1=(tmp[0]-'0')*1000+(tmp[1]-'0')*100+(tmp[2]=='F'?'E':tmp[2]);
	cin>>tmp;
	c2=(tmp[0]-'0')*10+(tmp[1]-'0')*1;
	cin>>tmp;
	s2=(tmp[0]-'0')*1000+(tmp[1]-'0')*100+(tmp[2]=='F'?'E':tmp[2]);
	if(c1==c2)cout<<1;
	else {
		cout<<0;
		f=0;
	}
	if(f && s2/100==s1/100)cout<<1;
	else {
		cout<<0;
		f=0;
	}
	if(f && ((s1%100>=68 && s2%100>=68)||(s1%100<68 && s2%100<68)))cout<<1;
	else {
		cout<<0;
		f=0;
	}
	if(f && abs(s1%100-s2%100)==1)cout<<1;
	else cout<<0;
	return 0;
} 

