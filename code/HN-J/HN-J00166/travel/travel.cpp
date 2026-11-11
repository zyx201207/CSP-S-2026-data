#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
bool e,f,g;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a == c){
		e = 1;
		cout << 1;
	}else{
		cout << 0;
	}if(e == 1 && b[0] == d[0] && b[1] == d[1]){
		f = 1;
		cout << 1;
	}else{
		cout << 0;
	}if(f == 1 && (b[2] >= 'A' && b[2] <= 'C') && (d[2] >= 'A' && d[2] <= 'C')){
		g = 1;
		cout << 1;
	}else if(f == 1 && (b[2] == 'D' || b[2] == 'F') && (d[2] == 'D' && d[2] == 'F')){
		g = 1;
		cout << 1;
	}else{
		cout << 0;
	}int z = (b[0]-'0')*10+b[1]-'0';
	int y = (d[0]-'0')*10+d[1]-'0';
	int x = b[2],w = d[2];
	if(g == 1 && abs(z-y) <= 1 && abs(x-w) <= 1){
		cout << 1;
	}else{
		cout << 0;
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
