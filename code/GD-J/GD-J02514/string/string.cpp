#include<bits/stdc++.h>
using namespace std;
int n;
struct s{
	int num;
	char c;
};
s a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int len = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i].num >> a[i].c;
		len += a[i].num;
	}
	long long ans = 0;
	int l = 0;
	char b = a[1].c;
	bool t = 0;
	
	for(int i = 1;i <= (n + 1) / 2;i++){
		int j = n - i + 1;
		if(t){
			a[j].num -= l;
			if(a[j].c != b) ans += l;
		}
		else{
			a[i].num -= l;
			if(a[i].c != b) ans += l;
		}
		if(a[i].c != a[j].c) ans += min(a[i].num,a[j].num);
		if(a[i].num < a[j].num){
			l = a[j].num - a[i].num;
			t = 0;
			b = a[j].c;
		}
		else{
			l = a[i].num - a[j].num;
			t = 1;
			b = a[i].c;
		}
	}
	cout << ans;
	return 0;
}
