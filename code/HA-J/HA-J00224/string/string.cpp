#include<bits/stdc++.h>
using namespace std;

long long n,a[200010],b,ans,lb;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	b = a[1]-a[n];
	for(int i = 1,j = n;i <= j;){
		if(c[i] != c[j]){
			if(lb == 0){
//				cout << lb << ' ';
				ans += min(a[i],a[j]);
			}else if(lb >= 1){
//				cout << lb << ' ';
				ans += lb;
			}else if(lb <= -1){
//				cout << lb << ' ';
				ans -= lb;
			}
//			cout << i << ' ' << j << ' ' << ans << '\n';
		}
		if(b == 0){
			lb = b;
			b = a[i]-a[j];
			i++;
			j--;
		}else if(b >= 1){
			lb = b;
			b -= a[j];
			j--;
		}else if(b <= -1){
			lb = b;
			b += a[i];
			i++;
		}
	}
	cout << ans;
	return 0;
}