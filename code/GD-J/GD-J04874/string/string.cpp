#include <iostream>
using namespace std;
long long n,arr[210005],c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++){
		cin >> arr[i];
		string t = "";
		cin >> t;
		for(int j = 1;j <= arr[i];j++) s += t;
	}
	for(long long i = 0,j = s.size() - 1;i <= s.size() / 2,j >= s.size() / 2;i++,j--){
		if(s[i] != s[j]){
			c++;
			s[j] = s[i];
		}
	}
	cout << c;
	return 0;
}
