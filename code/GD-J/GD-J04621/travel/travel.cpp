#include<bits/stdc++.h>
#define int long long
#define uint unsigned int
#define all(x) x.begin(),x.end()
#define inf 0x3f3f3f3f
using namespace std;
string rs,xs; int rc,xc;
char r[5],x[5]; bool flag = false;
int check(char a,char b){
	if(a=='A' || a=='B' || a=='C')
		if(b=='A' || b=='B' || b=='C')
			return 1;
	if(a=='D' || a=='F')
		if(b=='D' || b=='F')
			return 2;
	return 0;
}signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> rc >> rs >> xc >> xs;
	r[1] = rs[2]; x[1] = xs[2];
	r[2] = rs[0]; x[2] = xs[0];
	r[3] = rs[1]; x[3] = xs[1];
	if(rc == xc){
		cout << 1;
		flag = true;
	}else{
		flag = false;
		cout << 0;
	}if(flag && r[2] == x[2] && r[3] == x[3]){
		cout << 1;
		flag = true;
	}else{
		flag = false;
		cout << 0;
	}if(flag && check(r[1],x[1])){
		cout << 1;
		flag = true;
	}else{
		flag = false;
		cout << 0;
	}if(flag && check(r[1],x[1])==2){
		cout << 1;
		flag = true;
	}else if(flag && (r[1]+x[1] != 132)){
		cout << 1;
		flag = true;
	}else{
		cout << 0;
		flag = false;
	}return 0;
}
