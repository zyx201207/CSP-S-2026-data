#include<bits/stdc++.h>
using namespace std;
string c, b;
long long int n;
string aw;
const int N = 200005;
int a[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(long long int i = 0; i < n ; i++){
		cin >> a[i] >> b;
		for(long long int j = 0; j < a[i]; j++){
			c += b;
		}
	}
	long long int l = c.size();
	for(long long int i = ceil(l/2); i < l; i ++){
		if(c[i] != c[i - ceil(l/2) + 1])
		aw += 1;
	}
	cout << aw.size() ;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
