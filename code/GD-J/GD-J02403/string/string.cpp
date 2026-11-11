#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct Node{
	long long num;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].num >> a[i].c;
	}
	int l = 1,r = n;
	while(l < r){
		if(a[l].c != a[r].c){
			if(a[l].num > a[r].num){
				ans += a[r].num;
				a[l].num -= a[r].num;
				r--;
			}else{
				ans += a[l].num;
				a[r].num -= a[l].num;
				if(a[r].num == 0){
					r--;
				}
				l++;
			}
		}else{
			if(a[l].num > a[r].num){
				a[l].num -= a[r].num;
				r--;
			}else{
				a[r].num -= a[l].num;
				if(a[r].num == 0){
					r--;
				}
				l++;
			}
		}
	}
	cout << ans;
	return 0;
}

