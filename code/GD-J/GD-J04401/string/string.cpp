#include <bits/stdc++.h>
using namespace std;
struct str{
	long long num,start,end;
	char c;
}a[200010];
long long n,cnt,l;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	a[1].start = 1;
	for (int i = 1;i <= n;i++){
		cin >> a[i].num >> a[i].c;
		if (i != 1){
			a[i].start = a[i - 1].end + 1;
		}
		a[i].end = a[i].start + a[i].num - 1;
	}
	l = a[n].end;
	for (long long i = 1;i <= l / 2;i++){
		char c1,c2;
		long long i2 = l - i + 1;
		for (int j = 1;j <= n;j++){
			if (i >= a[j].start && i <= a[j].end){
				c1 = a[j].c;
			}
			if (i2 >= a[j].start && i2 <= a[j].end){
				c2 = a[j].c;
			}
		}
		if (c1 != c2){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
