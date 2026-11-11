#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
void print(int x){
	for(int i=1;i<=x;++i) cout<<0;
}
int js(char c){
	if(c<='C') return 1;
	return 0;
}
bool eq(char a,char b){
	if((a==b+1||b==a+1)&&a!='D'&&b!='D') return true;
	if(a=='D'&&b=='F') return true;
	if(a=='F'&&b=='D') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c) print(4);
	else{
		cout<<1;
		if(b[0]!=d[0]||b[1]!=d[1]) print(3);
		else{
			cout<<1;
			int id=js(b[2]),idy=js(d[2]);
			if(id!=idy) print(2);
			else{
				cout<<1;
				if(eq(b[2],d[2])) cout<<1;
				else cout<<0;
			}
		}
	}
	return 0;
}
