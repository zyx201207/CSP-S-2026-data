#include <bits/stdc++.h>
using namespace std;
#define in(s) freopen(#s ".in","r",stdin)
#define out(s) freopen(#s ".out","w",stdout)
#define int long long
const int N = 2e5+5;

int n;
int arr[N];
char crr[N];
int fr[N],ed[N];
int l,r;
int ans;

signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	in(string);
	out(string);
	cin >> n;
	for(int i=1;i<=n;i++)	cin >> arr[i] >> crr[i]; 
	for(int i=1;i<=n;i++)	fr[i] = fr[i-1]+arr[i];
	for(int i=n;i>=1;i--)	ed[i] = ed[i+1]+arr[i];
	l = 1, r = fr[n];
	int i = 1, j = n;
	while (i < j){
		if (fr[i] < ed[j]){
			int tep = fr[i]-l+1;
			if (crr[i]^crr[j])	ans += tep;
			l += tep;
			r -= tep;
			i++;
		}else{
			int tep = r-fr[j-1];
			if (crr[i]^crr[j])	ans += tep;
			l += tep;
			r -= tep;
			j--;
		}
	}
	cout << ans << endl;
	return 0;
}
/*

3
2 a
2 b
1 c


*/
