#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,x,a[N];
string m,y;
bool big(char c){
	if(x<='C')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y>>n>>m;
	if(x!=n){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	m = '.' + m,y = '.' + y;
	if(m[1] != y[1] || m[2] != y[2]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(big(m[3]) != big(y[3])){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(int(m[3]) - 1 == int(y[3]) || int(m[3]) + 1 == int(y[3])){
		cout<<"1";
		return 0;
	}
	cout<<0;
	return 0;
}
