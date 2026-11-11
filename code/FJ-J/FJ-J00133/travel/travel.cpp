#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f(char x,char y){
	if(x==y) return 1;
	else return 0;
}
int q(char z){
	if(z=='A'||z=='B'||z=='C') return 1;
	if(z=='F'||z=='D') return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	for(int j=0;j<=1;j++){
		if(f(a[j],c[j])==0){
			cout<<0<<0<<0<<0;
			return 0;
		}	
	}
	cout<<1;
	for(int j=0;j<=1;j++){
		if(f(b[j],d[j])==0){
			cout<<0<<0<<0;
			return 0;
		}	
	}
	cout<<1;
	if(q(b[2])!=q(d[2])){
		cout<<0<<0;
		return 0;
	}
	cout<<1;
	if(b[2]-d[2]==1||b[2]-d[2]==-1){
		cout<<1;
		return 0;
	}
	if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
