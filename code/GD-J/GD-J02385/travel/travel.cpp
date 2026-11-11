#include <bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> a >> m >> b;
	if(n==m){
		cout << "1";
		if(a[0] == b[0] && a[1] == b[1]){
			cout << "1";
			if((a[2] == 'A' && (b[2] == 'B' || b[2] == 'C'))||(a[2] == 'B' && (b[2] == 'A' || b[2] == 'C'))||(a[2] == 'C' && (b[2] == 'A' || b[2] == 'B'))||(a[2] == 'D' && b[2] == 'F')||(a[2] == 'F' && b[2] == 'D')){
				cout << "1";
			}else{
				cout << "00";
				return 0; 
			}
			if((a[2] == 'F' && b[2] == 'D')||(a[2] == 'D' && b[2] == 'F')||(a[2] == 'A' && b[2] == 'B')||(a[2] == 'B' && b[2] == 'A')||(a[2] == 'B' && b[2] == 'C')||(a[2] == 'C' && b[2] == 'B')){
				cout << "1";
			}else{
				cout << "0";
				return 0;
			}
		}else{
			cout << "000";
			return 0;
		}
	}else{
		cout << "0000";
		return 0;
	}
	return 0;
}
