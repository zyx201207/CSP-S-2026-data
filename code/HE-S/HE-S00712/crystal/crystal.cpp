#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n,ans;
long long s[N],t[N],a[N],d[N];
long long m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
	} 
	sort(a+1,a+n+1);
	bool ys = true;
	for(int i = 1;i<n;i++){
		d[i] = a[i+1] - a[i];
		s[i] = s[i-1] + d[i];
		t[i] = i*d[i]+t[i-1];
		if (i> 1 && d[i] != d[i-1]) ys = false; 
	}
	if (ys){
		for (int i = 1;i<n;i++){
			if (m>=(d[i]*i*(i-1)/2) && (d[i]*i*(i-1)/2) >= 0 && ans < i) ans = i;
		}
		cout << ans << endl;
	}else{
		bool c = true;
		for (int i = 1;i<n,c;i++){
			if (m >= t[i]) {
				if (ans < i+1) ans = i+1;
			}else{
				long long sum = t[i];
				int s1=1,e1=i+1;
				c = false;
				while(1){
					while(sum>m){
						sum -= s[e1-1] - s[s1-1];
						s1++;
					}
					while(e1<n&&sum<=m){
						ans = max(ans,e1-s1+1);
						sum += (e1-s1+1)*d[e1];
						e1++;
					}
					if (e1==n) {
						cout << ans << endl;
						break;
					}
				}
			}
			
		}
	}
	return 0;
} 









