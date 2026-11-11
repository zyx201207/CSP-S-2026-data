#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n = 0;
	cin >> n;
	
	string str = "";
	long long x;
	long long lon = 0;
	
	while (n--){
		cin >> x;
		char c;
		cin >> c;
		lon += x;
		while (x--){
			str += c;
		}
	}
	
	long long cnt = 0;
	for (int i=1; i<lon/2+1; i++){
		if (str[i] != str[lon-i-1])
			cnt++;
	}
	
	cout << cnt;
	
	return 0;
}
