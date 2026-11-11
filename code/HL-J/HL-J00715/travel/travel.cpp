#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string x1="A",x2="B",x3="C",x4="D",x5="F";
bool vis,v;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int x=stoi(c1),y=stoi(c2),a=stoi(s1.substr(0,2)),b=stoi(s2.substr(0,2));
	string d=s1.substr(2,1),z=s2.substr(2,1);
	if(x==y){
		cout<<1;
		v=1;
	}else cout<<0;
	if(a==b && v){
		cout<<1;
		vis=1;
	}else cout<<0;
	if((d==x1 || d==x2 || d==x3) && (z==x1 || z==x2 || z==x3) && vis && v) cout<<1;
	else if((d==x4 || d==x5) && (z==x4 || z==x5) && vis && v) cout<<1;
	else cout<<0;
	if(((z==x1 && d==x2) || (z==x2 && d==x3) || (z==x4 && d==x5)) && vis && v) cout<<1;
	else if(((d==x1 && z==x2) || (d==x2 && z==x3) || (d==x4 && z==x5)) && vis && v) cout<<1;
	else cout<<0;
	return 0;
}