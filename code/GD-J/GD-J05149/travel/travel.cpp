#include<bits/stdc++.h>
using namespace std;
long long a,b;
string a1,b1;
long long ak1,ak2,bk1,bk2;
char c;
queue<int> q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("tracel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	ak1=(a1[0]-48)*10+a1[1]-48;// 0 48
	ak2=a1[2];
	bk1=(b1[0]-48)*10+b1[1]-48;
	bk2=b1[2];
	if(a==b);
	else {cout<<"0000";return 0;}
	if(ak1==bk1);
	else {cout<<"1000";return 0;}//c 99 d 100
	if(ak2>99&&bk2>99||ak2<100&&bk2<100);
	else {cout<<"1100";return 0;}
	if(ak2+1==bk2||ak2-1==bk2)cout<<"1111";
	else{cout<<"1110";return 0;
	}
}
