#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, m, cnt = 0;
	cin >> n;
	string s;
	long long a[200005];
	char c[200005];
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		m += a[i];
	} 
	long long last_a;
	char last_c;
	long long i = 1, j = n, last_index;
	while(i <= j){
		long long maxa, mina;
		if(i != 1){
			mina = min(last_a, a[last_index]);
			maxa = max(last_a, a[last_index]);
			
			if(last_c != c[i]){
				
			}
		} else {
			mina = min(a[i], a[j]);
			maxa = max(a[i], a[j]);
		}
		last_a = maxa - mina;
		if(mina == a[j]){
			last_c = c[i];
			last_index = i;
			j--;
		}
		else{
			last_c = c[j];
			last_index = j;
			i++;
		}
		if(c[i] != c[j]){
			cnt += mina;
			continue; 
		}
	}
	/*
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= a[i]; j++){
			s += c[i];
		}
	}
	//cout << s << '\n';
	for(int i = 0, j = m - 1; i <= j; i++, j--){
		//cout << s[i] << ' ' << s[j] << ' ';
		if(s[i] != s[j]){
			cnt++;
			//cout << 'F';
		}/* else{
			cout << 'T';
		}
		cout << '\n';
	}*/
	cout << cnt;
	
	return 0;
} 

