#include<bits/stdc++.h>
using namespace std;
string s;
bool is(string a)
{
	long long num = a.size();
	for(long long i = 0;i < num/2;i++)
		if(a[i] != a[num-i-1]) return 0;
	return 1;
}
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int a[n];
	char c[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
		cin >> c[i];
		for(int j = 0;j < a[i];j++) s += c[i];
	}
	if(is(s)) cout << 0;
	else{
		long long n = s.size();
		long long sum = 0;
		for(long long i = 0;i < n/2;i++)
			if(a[i] != a[n-i-1]) sum++;
		cout << sum;
	}
	return 0;
}
