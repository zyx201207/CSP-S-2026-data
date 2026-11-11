//GZ-J00001 贵阳实验三中 夏上云 
#include <iostream>
using namespace std;

void f(string a){
	string temp = "";
	string temp1 = "";
	int cnt = 0;
	for(long long i = (a.size()-1)/2;i >= 1;i--){
		temp += a[i]; 
	}
	for(long long i = 1;i <= (a.size()-1)/2;i++){
		temp1 += a[i];
	}
	for(long long i = 0;i <= temp.size()-1;i++){
		if(temp[i] != temp1[i]) cnt++;
	}
	cout << cnt;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin >> t;
	string ans = "";
	while(t--){
		int n;
		char c; 
		cin >> n;
		cin >> c;
		for(int i = 1;i <= n;i++){
			ans += c;
		}
	}
	f(ans);
	return 0;
}
