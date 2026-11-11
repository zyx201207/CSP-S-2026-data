#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5+5;
int n,m;
int a[maxn];
int qzh[maxn];

bool check(int l,int r){
	return (a[r]*(r-l+1)-(qzh[r]-qzh[l-1])) <= m;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}sort(a+1,a+n+1);
	
	for (int i = 1;i <= n;i++){
		qzh[i] = qzh[i-1]+a[i];
	}
	
	int revans = 0;
	
	for (int i = 1;i <= n;i++){
		int ans = i,l = 1,r = i;
		while (l <= r){
			int mid = (l+r)>>1;
			if (check(mid,i)){
				ans = mid;
				r = mid-1;
			}else{
				l = mid+1;
			}
		}
		
		revans = max(revans,i-ans+1);
	}
	
	cout << revans;
}
