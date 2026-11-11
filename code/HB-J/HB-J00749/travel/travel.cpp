#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
char c1,c2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	if(a1!=a2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(b1!=b2){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((c1<='C'&&c2>'C')||(c1>='D'&&c2<'D')){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if((abs(c1-c2)==1)||(c1=='D'&&c2=='F')||(c1=='F'&&c2=='D')) cout<<1;
	else cout<<0;
	return 0;
}
