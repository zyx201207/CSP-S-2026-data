#include <bits/stdc++.h>
using namespace std;
struct s{
	int l;
	char c;
};
s a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans = 0,sum = 0;
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].l >> a[i].c;
		sum += a[i].l;
	}
	long long l = 0,r = 0,i = 1,j = n;
	char lc=0,rc=0;
	while(l+r+1< sum){
		if(l > r){
			int L = a[j--].l;
			r+= L;rc = a[j+1].c;
			if(l > r){
				if(lc != rc) ans += a[j+1].l;
			}else{
				if(lc != rc) ans += l-(r-a[j+1].l);
			}
		}else{
			if(rc == 0){
				r += a[j--].l;
				rc = a[j+1].c;
			}else{
				l += a[i++].l;
				lc = a[i-1].c;
				if(l > r){
					if(lc != rc){
						ans += r - l + a[i-1].l; 
					}
				}else{
					if(lc != rc){
						ans += a[i-1].l;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}

