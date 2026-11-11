#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;
int n;
int a[N];
int c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	vector<char> k;
	for (int i = 0;i < n;i++){
		cin >> a[i] >> c[i];
	}
	for (int i = 0;i < n;i++){
		for (int j = 0;j < a[i];j++){
			k.push_back(c[i]);
		}
	}
	long long l = k.size();
	int ans = 0;
	for (int i = 0;i < l/2;i++){
		if (k[i] != k[l-i-1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}




