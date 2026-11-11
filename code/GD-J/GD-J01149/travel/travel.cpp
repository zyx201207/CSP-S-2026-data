#include<bits/stdc++.h>
//#define int long long
using namespace std;
string a,b,c,d;
int e,f,g,h;
char x,y;
bool pd(char x,char y){
	if(x=='A'){
		if(y=='B')return 1;
		return 0;
	}if(x=='B'){
		if(y=='A'||y=='C')return 1;
		return 0;
	}if(x=='C'){
		if(y=='B')return 1;
		return 0;
	}if(x=='D'){
		if(y=='F')return 1;
		return 0;
	}if(x=='F'){
		if(y=='D')return 1;
		return 0;
	}
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	e=(a[0]-'0')*10+a[1]-'0';
	f=(b[0]-'0')*10+b[1]-'0';
	x=b[2];
	g=(c[0]-'0')*10+c[1]-'0';
	h=(d[0]-'0')*10+d[1]-'0';
	y=d[2];
	if(e==g){
		if(f==h){
			if(x<='C'&&y<='C'||x>'C'&&y>'C'){
				if(pd(x,y)){
					cout<<"1111";
				}else cout<<"1110";
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
} 
