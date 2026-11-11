#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a1,t1,t2,a2;
char b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>t1>>a1>>b1>>t2>>a2>>b2;
	if(t1!=t2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(a1!=a2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((b1<='C'&&b2>'C')||(b1>'C'&&b2<='C')){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if((b1+1==b2)||(b2+1==b1)){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
