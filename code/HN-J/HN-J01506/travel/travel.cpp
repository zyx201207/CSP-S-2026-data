#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
string xa,ya;
string xb,yb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xa>>xb>>ya>>yb;
	if(xa!=ya){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(xb[0]!=yb[0] or xb[1]!=yb[1]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	int f1=0,f2=0;
	if(xb[2]>='A'&&xb[2]<='C')f1++;
	if(yb[2]>='A'&&yb[2]<='C')f2++;
	if(f1+f2==1){
		cout<<"00";
		return 0;
	}else if(f1+f2==0){
		cout<<"11";
		return 0;
	}
	cout<<"1";
	if(abs(xb[2]-yb[2])==1){
		cout<<"1";
		return 0;
	}
	cout<<"0";
	return 0;
}
