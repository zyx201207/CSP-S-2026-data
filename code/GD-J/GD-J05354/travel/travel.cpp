#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b,c,d;
bool check1(char x,char y){
	return ('A'<=x&&x<='C'&&'A'<=y&&y<='C')||('D'<=x&&x<='F'&&'D'<=y&&y<='F');
}
bool check2(char x,char y){
	return x+1==y||y+1==x;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>b>>c>>d;
	if(a!=c)cout<<"0000";
	else {
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if(check1(b[2],d[2])){
				cout<<1;
				if(check2(b[2],d[2])){
					cout<<1;
				}else cout<<0;
			}else {
				cout<<"00";
			}
		}
		else cout<<"000";
	}
	
	return 0;
} 
