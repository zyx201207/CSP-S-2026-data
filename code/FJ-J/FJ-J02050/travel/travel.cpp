#include<bits/stdc++.h>
using namespace std;
bool check(char x,char y){
	if(x=='A'){
		return y=='B'||y=='C';
	}
	if(x=='B'){
		return y=='A'||y=='C';
	}
	if(x=='C'){
		return y=='B'||y=='A';
	}
	if(x=='F'){
		return y=='D';
	}
	if(x=='D'){
		return y=='F';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000\n";
	}else{
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			char x=b[2],y=d[2];
			if(check(x,y)){
				cout<<1;
				if(x=='A'&&y=='C'){
					cout<<0;
				}else if(x=='C'&&y=='A'){
					cout<<0;
				}else cout<<1;
			}else cout<<"00\n";
		}else cout<<"000\n";
	}
	return 0;
}
