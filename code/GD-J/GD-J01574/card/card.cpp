#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =5e5+10;
int a[maxn],n,m;
int d[maxn],b[maxn];
bool fi(int num,int n) {
	for(int i=n;i>=1;i--) {
		if(num==d[i]) {
			return 1;
		}
	}
	return 0;
}
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	for(int t=1;t<=n;t++) {
		memset(d,0,sizeof(d));
		int cnt=1;
		for(int i=t;i<=n;i++) {
			if(fi(a[i],cnt)) {
				int cnt2=cnt;
				while((fi(a[i],cnt))&&cnt2>0) {
					d[cnt2--]=0;
				} 
				cnt=cnt2+1;
			}
			d[cnt++]=a[i];
		}

		for(int i=1;i<=m;i++) {
			if(fi(i,cnt)) b[i]++;
		}
	}
	for(int i=1;i<=m;i++) {
		cout << b[i] << ' ';
	}
return 0;
} 
