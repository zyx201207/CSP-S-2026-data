#include <bits/stdc++.h>
using namespace std;
string s;
long long n,num[20000009],cmp,ans;
char c[200000009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++){
		cin >> num[i];
		cin >> c[i];
	}
    long long l = 1,r = n;
    while(l < r)
    {
		if(c[l] != c[r])
		{
			ans+=num[l];
		}
		l++,r--;
	}
	cout << ans;
	return 0;
}
