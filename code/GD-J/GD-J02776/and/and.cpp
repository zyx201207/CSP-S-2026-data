#include <bits/stdc++.h>
using namespace std;
typedef long long lng;
void chg(lng& e,lng c,int& d){
	lng a=c;
	e=0;
	string b="";
	while(a>0){
		b+=a%2;
		a/=2;
		cout<<"&:"<<a<<" "<<endl;
	}
	for(int i=d;i>=0;i--){
		e+=a;
		e*=10;
	}
	cout<<e;
}
int ori(lng b,int c){
	lng a=0;
	int v=1;
	for(int i=0;i<c;i++){
		a+=b%10*v;
		b/=10;
	}
	return a;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin>>n>>m;
	lng a[n],t[n]={0},p[n][n]={1};  //a: input, l: length, t: (2), p: output
	int l[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
		chg(t[i],a[i],l[n]);
		cout<<t[i]<<endl;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(lng k=0;k<min(l[i],l[j]);k++){
				p[i][j]*=10;
				int q=0;
				if(t[i]==t[j])q=1;
				p[i][j]+=q;
				cout<<"&&:"<<q<<endl;
			}
			cout<<p[i][j]<<endl;
		}
	}
	lng b=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			p[i][j]=ori(p[i][j],min(l[i],l[j]));
			b=max(p[i][j],b);
		}
	}
	cout<<b;
}
