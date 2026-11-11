#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
char c[MAXN];
int a[MAXN];
int n;
long long cnt = 0;

int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i ++) {
    	cin >> a[i] >> c[i];
	}
	
	int l = 1, r = n;
	
	while (l <= r) {
		if(a[l] < a[r]) {
			long long x = a[r] - a[l];
			if(c[l] != c[r]) {
				cnt += a[l];
			}
			a[r] = x;
			a[l] = 0;
			l++;
		} else if(a[l] > a[r]) {
			long long x = a[l] - a[r];
			if(c[l] != c[r]) {
				cnt += a[r];
			}
			a[l] = x;
			a[r] = 0;
			r--;
		} else if(a[l] == a[r]) {
			long long x = a[r];
			if(c[l] != c[r]) {
				cnt += x;
			}
			a[r] = 0;
			a[l] = 0;
			l++; r--;
		}
	}
	if(c[l] != c[r]) {
		cnt += a[l];
		cnt += a[r];
	}

       
    cout << cnt;

	return 0;
}
