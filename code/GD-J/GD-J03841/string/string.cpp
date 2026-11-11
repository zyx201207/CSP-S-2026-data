#include <bits/stdc++.h>
using namespace std;
long long sum,b[200005],n,a[200005],d[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i = 1; i <= n; i++){
		cin>>a[i]>>c[i];
		b[i] = b[i - 1] + a[i];
	}
	for (int i = n; i >= 1; i--){
		d[i] = d[i + 1] + a[i];
	}
	long long l1 = 1,r1 = n,len = b[n] / 2;
	int last = 0;
	if (b[n] & 1){
		len++;
	}
	while (b[l1 - 1] <= len && d[r1 + 1] <= len && l1 <= r1){
		if (c[l1] != c[r1]){
			if (last == 0){
				sum += min(a[l1],a[r1]);
			}else if (last == 1){
				sum += min(d[r1] - b[l1 - 1],a[l1]);
			}else{
				sum += min(b[l1] - d[r1 + 1],a[r1]);
			}
//			cout<<l1<<" "<<r1<<'\n';
		}
		if (b[l1] < d[r1]){
			l1++;
			last = 1;
		}else if (b[l1] > d[r1]){
			r1--;
			last = 2;
		}else{
			l1++;
			r1--;
			last = 0;
		}
	}
	cout<<sum<<'\n';
	return 0;
}
