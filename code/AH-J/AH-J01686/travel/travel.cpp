#include<bits/stdc++.h>
using namespace std;

char a,b,c,d,e;
char m,n,x,y,z;
int w,p;

bool fun(char i,char j){
	if(i=='A'||i=='B'||i=='C'){
		w=1;
	}
	else w=2;
	if(j=='A'||j=='B'||j=='C'){
		p=1;
	}
	else p=2;
	if(w==p){
		return 1;
	}
	else return 0;
}

bool fun2(char i,char j){
	if(w==1){
		if(i=='A'&&j=='B')
			return 1;
		if(i=='B'&&j=='A')
			return 1;
		if(i=='B'&&j=='C')
			return 1;
		if(i=='C'&&j=='B')
			return 1;
	}
	else if(w==2){
		return 1;
	}
	return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>a>>b>>c>>d>>e;
	cin>>m>>n>>x>>y>>z;
	
	if(a==m&&b==n){
		cout<<"1";
		if(c==x&&d==y){
			cout<<"1";
			if(fun(e,z)){
				cout<<"1";
				if(fun2(e,z)){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else {
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
	return 0;
}
