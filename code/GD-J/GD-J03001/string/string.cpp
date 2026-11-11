#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct str{
	int a;
	char c;
};
str s[N];

string add(string a, int b){
	
	int i = a.size()-1;
	
	while(b){
		
		if(i == -1){
			i = 0;
			char c = b%10 + '0';
			a = c + a;
		}
		else{
			a[i] = (b%10) + a[i];
		}
		
		b /= 10;
		i--;
	}
	
	for(int i = a.size()-1; i > 0; i--){
		
		if(a[i] > '9'){
			a[i-1] = a[i-1] + 1;
			a[i] = (a[i] - 10);
		}
		
	}
	
	if(a[0] > '9'){
		a[0] = a[0] - 10;
		a = '1' + a;
	}
	
	return a;
}

int main(){
	
	freopen("string.in", "w", stdin);
	freopen("string.out", "r", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> s[i].a >> s[i].c;
	}
	
	int i = 1, j = n;
	string ans = "0";
	int sumi = s[i].a, sumj = s[j].a;
	
	while(i < j){
		
		int ch = min(sumi, sumj);
		sumi -= ch;
		sumj -= ch;
		
		if( s[i].c != s[j].c ){
			ans = add(ans, ch);
		}
		
		if(sumi == 0){
			i++;
			sumi = s[i].a;
		}
		if(sumj == 0){
			j--;
			sumj = s[j].a;
		}
		
	}
	
	cout << ans;
	
	return 0;
}
