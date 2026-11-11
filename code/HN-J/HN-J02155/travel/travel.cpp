#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int n1,n2;
string m1,m2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>m1>>n2>>m2;
	if(n1!=n2){
		cout<<"0000";
		return 0;
	}
	int a=10*(m1[0]-'0')+m1[1]-'0';
	int b=10*(m2[0]-'0')+m2[1]-'0';
	if(a!=b){
		cout<<1000;
		return 0;
	}
	char n=m1[2],m=m2[2];
	if(n>m)swap(n,m);
	if(n<='C'&&m>='D'){
		cout<<1100;
		return 0;
	}
	if(n=='A'&&m=='C'){
		cout<<1110;
		return 0;
	}
	cout<<1111;
	return 0;
}
