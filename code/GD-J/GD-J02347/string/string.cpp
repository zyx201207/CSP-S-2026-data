#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char c;
}a[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].num >> a[i].c;
	}
	int l = 1,r = n;
	long long ans = 0;
	while(l <= r){
		while(a[l].num == 0) l++;
		while(a[r].num == 0) r--;
		if(a[l].c != a[r].c){
			long long num = abs(a[l].num - a[r].num);
			ans += max(a[l].num,a[r].num);
			int pos = r;
			while(num > 0){
				if(a[pos].num >= num){
					a[r].num += num;
					a[pos].num -= num;
					break;
				}
				else{
					a[r].num += a[pos].num;
					a[pos].num = 0;
				}
				ans++;
			}
		}
		l++;
		r--;
		if(l == r) break;
	}
	cout << ans;
	return 0;
}
