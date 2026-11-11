#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << 0 << 0 << 0 << 0;
	}else{
		cout << 1;
		int ans = 0, sum = 0;
		int a, b;
		for(int i = 0; i < s1.size()-1; i++){
			ans = ans*10 + s1[i] - '0';
		}
		a = s1[s1.size()-1] - 'A'+1;
		b = s2[s2.size()-1] - 'A'+1;
		for(int i = 0; i < s2.size()-1; i++){
			sum = sum*10 + s2[i] - '0';
		}
		if(ans == sum) cout << 1;
		else {
			cout << 0 << 0 << 0;
			return 0;	
		}
		if(a >=1 && a <= 3 && b >= 1 && b <= 3) cout << 1;
		else if(a >= 4 && a <= 5 && b >= 4 && b <= 5){
			cout << 1;
		}else {
			cout << 0 << 0;
			return 0;
		}
		if(abs(a-b) == 1){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	return 0;
}

