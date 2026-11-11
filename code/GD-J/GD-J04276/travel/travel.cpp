#include<bits/stdc++.h>
using namespace std;
#define ll long long
void fo(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	return;
}
map<char,bool>m;
map<char,int>m2;
void sol(){
	m['A']=1,m['B']=1,m['C']=1,m['D']=0,m['F']=0;
	m2['A']=1,m2['B']=2,m2['C']=3,m2['D']=5,m2['F']=6;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<1000;
		return;
	}
	if(m[s1[2]]^m[s2[2]]){
		cout<<1100;
		return;
	}
	if(abs(m2[s1[2]]-m2[s2[2]])>1){
		cout<<1110;
		return;
	}
	cout<<1111;
	return;
}
int main(){
	fo();
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		sol();
	}
	return 0;
}
