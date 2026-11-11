#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
string tt(int a){
	string s = "";
	while(a > 0){
		char ss = '0' + a % 2;
		s += ss;
		a /= 2;
	}
	return s;
}
string annd(string a,string b){
	string s = "";
	for(int i = min(a.length(),b.length()) - 1;i >=0;i--){
		if(a[i] == b[i]){
			s += '1';
		}
		else{
			s += '0';
		}
	}
	return s;
}
int to_ten(string a){
	long long num = 0;
	int wq = 1;
	for(int i = a.length()-1;i>=0;i--){
		num += wq * (a[i] - '0');
		wq *= 2;
	}
	return num;
}
bool cpp(int a,int b){
	return a > b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cpp);
	string aaaa = tt(a[1]);
	for(int i = 2;i<=m;i++){
		aaaa = annd(aaaa,tt(a[i]));
	}
	cout << to_ten(aaaa);
	return 0;
}
