#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int turn(string a){
	return int(a[0]-'0') + int(a[1]-'0');
}

void solve(string a,string x,string b,string y){
	int aa= turn(a); int bb= turn(b);
	int xx= turn(x); int yy= turn(y);
	int m=int(char(x[2])-'A');
	int n=int(char(y[2])-'A');
	
	if(aa!=bb){
		cout<<"0000";
		return;
	}
	
	if(xx!=yy){
		cout<<"1000";
		return;
	}
	
	if((char(x[2])=='D'&&char(y[2])=='F') || (char(x[2])=='F'&&char(y[2])=='D')){
		cout<<"1111";
		return;
	}
	
	if((n==0&&m==1)||(n==1&&m==0)||
	(n==1&&m==2)||(n==2&&m==1)||
	(n==5&&m==3)||(n==5&&m==3)){
		cout<<"1111";
		return;
	}
	
	if((n==0&&m==2)||(n==2&&m==0)){
		cout<<"1110";
		return;
	}
	
	cout<<"1100";
	return;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	solve(c1,s1,c2,s2);
	return 0;
} 
