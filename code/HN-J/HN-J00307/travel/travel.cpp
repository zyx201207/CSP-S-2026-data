#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e4 + 5;
bool flag = 0;
string a,c;
string b,d;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << 1;
	}else{
		flag = 1;
		cout << 0 ;
	}
	if(flag == 1){
		cout << "000";
		return 0;
	}
	if(b[0] == d[0] && b[1] == d[1]){
		cout << 1;
	}else{
		cout << 0 ;
	}
	if(b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C' && b[1] == d[1] or b[2] >= 'D' && b[2] <= 'F' && d[2] >= 'D' && d[2] <= 'F'){
		cout << 1;
	}else{
		cout << 0;
	}
	if(b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C' && abs(int(d[2] - 1))== b[2] or b[2] >= 'D' && b[2] <= 'F' && d[2] >= 'D' && d[2] <= 'F' && abs(int(d[2] - 2)) == b[2] && (b[2] != 'c' && d[2] == 'D')){
		cout << 1;
	}else{
		cout << 0 ;
	}
    return 0;
}
