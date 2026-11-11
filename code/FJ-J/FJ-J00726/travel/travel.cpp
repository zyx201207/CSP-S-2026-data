#include<bits/stdc++.h>
int namespace std;
int main(){
	int a,b;
	string c,d;
	freopen("travel",r,"travel.in",stdin);
	freopen("travel",w,"travel.out",stdout);
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<1;
	}
	else{
		cout<<0000;
		return 0;
	}
	if(c[0]==d[0]&&c[1]==d[1]){
		cout<<1;
	}
	else{
		cout<<000;
		return 0;
	}
	if(c[2]=='A'&&d[2]=='B'||c[2]=='B'&&d[2]=='C'||d[2]=='A'&&c[2]=='B'||d[2]=='B'&&c[2]=='C'||c[2]=='F'&&d[2]=='D'||c[2]=='D'&&d[2]=='F'){
		cout<<11;
		return 0;
	}
	else if(c[2]=='A'&&d[2]=='C'){
		cout<<10;
		return 0;
	}
	cout<<00;
	return 0;
}
