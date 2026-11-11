#include <bits/stdc++.h>
using namespace std;
struct node{
	long long g;
	char c;
}a[2000010];
long long n,ans = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(long long i = 0;i < n;i++){
		cin >> a[i].g >> a[i].c;
	}
	long long l = 0,r = n - 1;
	while(l < r){
		if(a[l].c != a[r].c){
			if(a[l].g > a[r].g){
				ans += a[r].g;
				a[l].g -= a[r].g;
				r--;
			}else if(a[l].g < a[r].g){
				ans += a[l].g;
				a[r].g -= a[l].g;
				l++;
			}else{
				ans += a[l].g;
				l++;
				r--;
			}
		}else{
			if(a[l].g > a[r].g){
				a[l].g -= a[r].g;
				r--;
			}else if(a[l].g < a[r].g){
				a[r].g -= a[l].g;
				l++;
			}else{
				l++;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
