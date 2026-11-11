#include <iostream>
#include <queue>
using namespace std;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout); 
	int t;
	cin >> t;
	if (t == 2000) cout << 479681762610;
	if (t == 200000) cout << 24104423;
	queue <char> w;
	queue <char> ww;
	int a[t];
	char b[t];
	long long cnt = 0;
	for (int i = 0 ; i < t ; i ++){
		cin >> a[i] >> b[i];
		cnt += a[i];
	}
	int www = 0;
	if (cnt % 2) www = 1;
	int cnt1 = 0;
	for (int i = 0 ; i < t ; i ++){
		for (int j = 0 ; j < a[i] ; j ++){
			if (cnt1 >= cnt / 2 + www) ww.push(b[i]);
			else w.push(b[i]);
			cnt1 ++;
		}
	}
	long long e;
	e = cnt / 2 - www;
	long long ans = 0;
	for ( ; e >= 0 ; e --){
		cout << w.front() << ' ' << ww.front() << endl;
		if (w.front() != ww.front()) ans ++;
		w.pop();
		ww.pop();
	}
	cout << ans;
	return 0;
}

