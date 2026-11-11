#include<bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
void print(){
	cout<<0<<0<<0<<0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==1||c==1||a==16||c==16){
		print();
		return 0;
	}
	if(a==c){
		cout<<1;
	}else{
		print();
		return 0;
	}
	int n=(b[0]-'0')*10+b[1]-'0';
	int m=(d[0]-'0')*10+d[1]-'0';
	if(n==m){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(b[2]!=d[2]){
		if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))){
			cout<<1;
		}else{
			cout<<0<<0;
			return 0;
		}
	}else{
		cout<<0<<0;
		return 0;
	}
	if(((b[2]+1==d[2])||(b[2]-1==d[2]))||((b[2]+2==d[2])||(b[2]-2==d[2]))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
