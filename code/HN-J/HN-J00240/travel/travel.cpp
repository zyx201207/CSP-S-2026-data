#include<bits/stdc++.h>
#define int long long
using namespace std;
string l1,l2;
string r1,r2;
bool check1(){
	return l1==r1;
}
bool check2(){
	return l2[0]==r2[0]&&l2[1]==r2[1];
}
bool check3(){
	char x=l2[2];
	char y=r2[2];
	int l=0,r=0;
	if(x=='D'||x=='E'){
		l=1;
	}
	if(y=='D'||y=='E'){
		r=1;
	}
	return l==r;
}
bool check4(){
	char x=l2[2];
	char y=r2[2];
	if(x+1==y||x-1==y)return true;
	else return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>l1>>l2>>r1>>r2;
	if(check1()){
		cout<<1;
		if(check2()){
			cout<<1;
			if(check3()){
				cout<<1;
				if(check4()){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
