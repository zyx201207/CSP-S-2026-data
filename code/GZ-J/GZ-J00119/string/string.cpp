//GZ-J00119 高闻达
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	long long cnt=0,v;
	cin >> n;
	vector<long long>a(n);
	vector<char>c(n);
	for(int i = 0;i < n;i++){
		cin >> a[i] >> c[i];
		for(int j = 0;j < a[i];j++){
			s += c[i];
		}
	}
	v = s.size();
	for(int i = 0;i < v/2;i++){
		if(s[i] == s[v-i-1]){
		}
		else{
			cnt++;
		}
	}
	cout << cnt;
	return 0;

}
