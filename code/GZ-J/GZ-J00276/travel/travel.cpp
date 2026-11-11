//GZ-J00276 »ÆÈË÷ë 
#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
set<char> l,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	l.insert('F'),l.insert('D');
	r.insert('A'),r.insert('B'),r.insert('C');
	if(c1==c2) cout<<1;
	else return cout<<"0000",0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1; 
	else return cout<<"000",0;
	if((l.find(s1[2])!=l.end()&&l.find(s2[2])!=l.end())||(r.find(s1[2])!=r.end()&&r.find(s2[2])!=r.end())) cout<<1;
	else return cout<<"00",0;
	if(s1<s2) swap(s1,s2);
	if(s1[2]-s2[2]==1) cout<<1;
	else cout<<0;
	return 0;
}
