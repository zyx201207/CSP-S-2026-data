#include<bits/stdc++.h>
using namespace std;
string r(string a){
	string b = "";
	for(int i = a.size() - 1;i >= 0;i--){
		b += a[i];
	}
	return b;
}
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long n,sum = 0;
	double e;
	cin >> n;
	string b = "",d = "",f = "";
	long long a[n];
	char c[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
		cin >> c[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < a[i];j++){
			b += c[i];
		}
	}
	e = b.size();
	if(b.size() % 2 == 0){
		for(int i = 0;i < b.size() / 2;i++){
			d += b[i];
		}
	}
	else{
		for(int i = 0;i < ceil(e / 2) - 1;i++){
			d += b[i];
		}
	}
	if(b.size() % 2 == 0){
		for(int i = b.size() / 2 + 1;i < b.size();i++){
			f += b[i];
		}
	}
	else{
		for(int i = ceil(e / 2);i < b.size();i++){
			f += b[i];
		}
	}
	f = r(f);
	for(int i = 0;i < d.size();i++){
		if(d[i] != f[i]) sum++;
	}
	cout << sum;
	fclose(stdin);
    fclose(stdout);
	return 0;
}