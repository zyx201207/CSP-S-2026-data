#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string c1x,s1x,c2x,s2x;
int c1,c2,s1,s2;
char t1,t2;
bool f1,f2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1x>>s1x>>c2x>>s2x;
	c1=(c1x[0]-'0')*10+(c1x[1]-'0');
	c2=(c2x[0]-'0')*10+(c2x[1]-'0');
	if(c1==c2)cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	s1=(s1x[0]-'0')*10+(s1x[1]-'0');
	s2=(s2x[0]-'0')*10+(s2x[1]-'0');
	if(s1==s2)cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	t1=s1x[2],t2=s2x[2];
	if(t1=='A'||t1=='B'||t1=='C')f1=1;
	else f1=0;
	if(t2=='A'||t2=='B'||t2=='C')f2=1;
	else f2=0;
	if(f1==f2)cout<<'1';
	else{
		cout<<"00";
		return 0;
	}
	if(max(t1,t2)-min(t1,t2)==1)cout<<'1';
	else cout<<'0';
	return 0;
}
