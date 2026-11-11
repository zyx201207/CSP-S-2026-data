#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<long long> a;
vector<int> c;

int str_of(long long index){
	index++;
	long long i = 0;
	while (index > a[i]){
		index -= a[i];
		i++;
	}
	return c[i];
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	long long str_size = 0;
	for (int i = 0;i < n;i++){
		long long a1;
		char c1;
		cin >> a1 >> c1;
		a.push_back(a1);
		c.push_back(c1);
		str_size += a1;
	}
	
	long long wrong = 0;
	for (int i = 0;i < str_size / 2;i++){
//		cout << str_of(i) << ' ' << str_of(str_size - i - 1) << endl;
		if (str_of(i) != str_of(str_size - i - 1)){
			wrong++;
		}
	}
	cout << wrong << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
