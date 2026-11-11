#include <iostream>
using namespace std;

long long n;
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i=0;i<n;i++){
		long long a;
		char c;
		cin >> a >> c;
		for (int j=0;j<a;j++){
			s += c;
		}
	} // ¶ÁÈ¡×Ö·û´®s 
	
	long long sum=0;
	for (int i=0;i<s.size()/2;i++){
		if (s[i] != s[s.size()-1-i]){
			sum++;
		}
	}
	cout << sum; 
	return 0;
}
