#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N=1e5+10;
vector<int> G[N];
int n,m,t;
string a,b,c,d;
int chea=0,cheb=0;
int posa=0,posb=0;
int ca,cb;
int check1(){
	if(chea==cheb)return 1;
	return 0;
}
int check2(){
	if(!check1())return 0;
	if(posa==posb)return 1;
	return 0;
}
int check3(){
	if(!check1()||!check2())return 0;
	if((ca>=0&&ca<=2&&cb>=0&&cb<=2))return 1;
	if((ca>=3&&ca<=4&&cb>=3&&cb<=4))return 1;
	return 0;
}
int check4(){
	if(!check1()||!check2())return 0;
	if(check3()){
		if(ca+1==cb||cb+1==ca)	return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;

	for(int i=0;i<2;i++){
		chea=chea*10+a[i]-'0';
	}
	for(int i=0;i<2;i++){
		cheb=cheb*10+c[i]-'0';
	}
	for(int i=0;i<2;i++){
		posa=posa*10+b[i]-'0';
	}
	ca=b[2]-'A';
	for(int i=0;i<2;i++){
		posb=posb*10+d[i]-'0';
	}
	cb=d[2]-'A';
	cout<<check1();
	cout<<check2();
	cout<<check3();
	cout<<check4();
}
