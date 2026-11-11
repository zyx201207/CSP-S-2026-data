#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN],cnt = 0,n;
char c[MAXN];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1 ; i<=n ; i++) cin >> a[i] >> c[i];
	int left = 1,right = n;
	while(left < right){
		//cout << left << ' ' << right << endl;
		if(c[left] != c[right]) cnt += min(a[left],a[right]);
		if(a[left]-a[right]>=0){
			int t = a[left]-a[right];
			a[left] = t;
			a[right] = 0;
		}else{
			int t = a[right]-a[left];
			a[left] = 0;
			a[right] = t;
		}
		if(a[left] == 0) left++;
		if(a[right] == 0) right--;
	}
	cout << cnt;
	return 0;
}
