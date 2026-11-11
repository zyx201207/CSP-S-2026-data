#include<bits/stdc++.h>
using namespace std;
long long sum;
long long cnt;
long long ans;
struct node{
	long long c;
	string s;
}a[200005];
long long suml, sumr;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i].c >> a[i].s;
		sum += a[i].c;
	}
	if (sum % 2 == 1){
		for (int i = 1; i <= n; i++){
			ans += a[i].c;
			if (ans >= sum / 2 + 1){
				a[i].c--;
				sum--;
				break;
			}
		}
	}
	int l = 1, r = n;
	while(suml < sum / 2 && sumr < sum / 2 && l <= r){
		if (a[l].s == a[r].s){
			if (a[l].c > a[r].c){
				sumr += a[r].c;
				a[l].c -= a[r].c;
				r--;
			}
			else if (a[r].c > a[l].c){
				suml += a[l].c;
				a[r].c -= a[l].c;
				l++;
			}
			else{
				suml += a[l].c;
				sumr += a[r].c;
				l++;
				r--;
			}
		}
		else{
			if (a[l].c > a[r].c){
				sumr += a[r].c;
				cnt += a[r].c;
				a[l].c -= a[r].c;
				r--;
			}
			else if (a[r].c > a[l].c){
				suml += a[l].c;
				cnt += a[l].c;
				a[r].c -= a[l].c;
				l++;
			}
			else{
				suml += a[l].c;
				sumr += a[r].c;
				cnt += a[l].c;
				l++;
				r--;
			}
		}
//		cout << l << " " << r << " " << suml << " " << sumr << " " << cnt << '\n';
	}
	cout << cnt;
	return 0;
}
