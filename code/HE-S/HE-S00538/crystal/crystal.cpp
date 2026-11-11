#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 500005;
long long a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n, m, b = 0, ans = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i = 1; i < n; i++){
		if(m<0){
			break;
		}
		b = a[i]-a[i-1];
		m-=b*i;
		ans++;
	}
	cout << ans;
	return 0;
} 
