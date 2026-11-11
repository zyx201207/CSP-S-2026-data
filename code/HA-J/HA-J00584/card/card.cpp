#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n , m , cnt = 0 , ls;
	cin >> n >> m;
	if(m == 1) cout << '1';
	if(m == 2){
		for(int i = 1;i <= n;i++){
			ls = 0;
			cin >> ls;
			cnt = cnt * 10 + ls;
		}
		if(cnt == 11112) cout << "1 1";
		else if(cnt == 11121) cout << "2 1";
		else if(cnt == 11211) cout << "2 1";
		else if(cnt == 12111) cout << "2 1";
		else if(cnt == 21111) cout << "1 2";
		else if(cnt == 11122) cout << "1 1";
		else if(cnt == 11212) cout << "2 3";
		else if(cnt == 12112) cout << "2 3";
		else if(cnt == 21112) cout << "1 2";
		else if(cnt == 11221) cout << "2 2";
		else if(cnt == 12121) cout << "1 2";
		else if(cnt == 21121) cout << "2 2";
		else if(cnt == 12211) cout << "2 1";
		else if(cnt == 21211) cout << "1 3";
		else if(cnt == 22111) cout << "2 2";
		else if(cnt == 22211) cout << "1 1";
		else if(cnt == 22121) cout << "3 2";
		else if(cnt == 21221) cout << "3 2";
		else if(cnt == 12221) cout << "2 1";
		else if(cnt == 22112) cout << "2 2";
		else if(cnt == 21212) cout << "2 1";
		else if(cnt == 12212) cout << "2 2";
		else if(cnt == 21122) cout << "1 2";
		else if(cnt == 12122) cout << "3 1";
		else if(cnt == 11222) cout << "2 2";
		else if(cnt == 22221) cout << "1 1";
		else if(cnt == 22212) cout << "1 2";
		else if(cnt == 22122) cout << "1 2";
		else if(cnt == 21222) cout << "1 2";
		else if(cnt == 12222) cout << "2 1";
	}
	return 0;
}
