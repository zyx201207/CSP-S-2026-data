#include<bits/stdc++.h>
using namespace std;

long long n, m, a[200005], d[200005], ma, maa, aa;

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];  
		maa=max(maa, a[i]); 
		if (i<=2)
			aa=a[1]&a[2];
		aa&=a[i];   
	}
	if (m==n){
		cout << aa;
		return 0;
	}
	if (m==1){
		cout << maa;
		return 0;
	}
	if (m==2) {
		maa=a[1]&a[2];
		for (int i=1; i<=n; i++) 
		for (int j=i-1; j>0; j--)
			maa=max(maa, a[i]&a[j]);
		cout << maa;
		return 0;
	}
	if (m+1==n){
		for (int i=1; i<=n; i++){
			aa=a[(i+1)%n]&a[(i+2)%n];
			for (int j=1; j<=n; j++)
				if (j!=i)
					aa&=a[j];
			if (i==1)
				maa=aa;
			maa=max(maa, aa);
		}
		cout << maa;
		return 0;
	}
	d[2]=a[1]&a[2];
	for (int i=1; i<=n; i++) {
		for (int j=i-1; j>0; j--)
			d[2]=max(d[2], a[i]&a[j]);
		ma=max(ma, d[2]);
		d[2]=max(ma, d[2]);
		for (int j=m; j>2; j--) {
			d[j]=max(d[j], d[j-1]&a[i]);
		}
	}
	cout << d[m] << '\n';
	return 0;
}
// rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++
// T3，4做不出，我已急哭，搞了1.5h94不行，还不知道 
// 今年竟然算简单，没考树和图，考了我就完了，好善良的一年 
