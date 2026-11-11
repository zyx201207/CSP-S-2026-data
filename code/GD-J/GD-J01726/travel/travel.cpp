#include<bits/stdc++.h>
using namespace std;
long long x,y;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> x >> a >> y >> b;
	if (x==y){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	if (a[0]==b[0]&&a[1]==b[1]){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	if (a[2]=='D'||a[2]=='F') x=1;
	else x=2;
	if (b[2]=='D'||b[2]=='F') y=1;
	else y=2;
	if (x==y){
		cout << "1";
	}else{
		cout << "00";
		return 0;
	}
	if (x==1&&y==1) cout << "1";
	else if (a[2]+1==b[2]||a[2]==b[2]+1) cout << "1";
	else cout << "0";
	return 0;
}
