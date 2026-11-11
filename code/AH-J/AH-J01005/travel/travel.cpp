#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num(string s){
	return (s[0]-'0')*10+(s[1]-'0');
}
bool check(char a,char b,char x,char y){
	return (a==x&&b==y)||(a==y&&b==x);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	ll x=num(a),y=num(c);
	if(x==y){
		cout<<1;
		x=num(b),y=num(d);
		if(x==y){
			cout<<1;
			char c1=b[2],c2=d[2];
			if((c1!='F'&&c2!='F'&&c1!='D'&&c2!='D')||(c1!='A'&&c2!='A'&&c1!='B'&&c2!='B'&&c1!='C'&&c2!='C')){
				cout<<1;
				if(check(c1,c2,'F','D')||check(c1,c2,'A','B')||check(c1,c2,'B','C')){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
