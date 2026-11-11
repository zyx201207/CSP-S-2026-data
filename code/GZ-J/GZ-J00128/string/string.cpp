//GZ-J00128 遵义市第十二中学 戴沉鑫 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n, cnt = 0;
	long long a[20005], d[20005];
	char c[20005], e[20005];
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		d[i] = a[i], e[i] = c[i];
	}
	int k = n;
	int x;
	if(n % 2 == 0) x = n / 2;
	else x = n / 2 + 1;
	for(int i = 1; i <= x; i++){
		if(a[i] == a[k] && c[i] == c[k] || c[i] == c[k]){
			cnt++;
		}
		k--;
	}
	if(cnt == x){
		cout << "0";
		return 0;
	}
	cnt = 0;
	k = n;
	for(int i = 1; i <= x; i++){
		swap(d[i], d[k]);
		swap(e[i], e[k]);
		k--;
	}
	for(int i = 1; i <= n; i++){
		if(a[i] != d[i] && c[i] != e[i])
			cnt += min(a[i], d[i]);
		else if(a[i] != d[i] && c[i] == e[i])
			cnt += max(a[i], d[i]) - min(a[i], d[i]);
		else if(a[i] == d[i] && c[i] != e[i])
			cnt += a[i];
		else if(a[i] == d[i] && c[i] == e[i])
			continue;
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
}

