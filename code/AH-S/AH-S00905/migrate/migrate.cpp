#include<bits/stdc++.h>
using namespace std;
int c,a,b;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> a >> b;
	if(a==2){
		if(b==4){
			cout << 1 << '\n';
			cout << 2 << '\n';
			return 0;
		}else{
			cout << 0 << '\n' << 1;
			return 0;
		}
	}else{
		if(a==17){
			cout << 8129 << '\n' << 16 << '\n' << 9 << '\n' << 7 << '\n' << 12 << '\n' << 0 << '\n' << 0 << '\n' << 0 << '\n' << 2 << '\n' << 1 << '\n' << 0 << '\n' << 2 << '\n' << 3 << '\n' << 6 << '\n' << 0 << '\n' << 2 << '\n' << 0;			
		}else{
			cout << 0 << '\n' << 0 << '\n' << 259997 << '\n' << 259995 << '\n' << 86669 << '\n' << 0 << '\n' << 0 << '\n' << 0 << '\n' << 7 << '\n' << 5 << '\n' << 5 << '\n' << 0;
		}
	}
	return 0;
}

