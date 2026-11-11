#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5+5;

int a[N],s[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	s[0] = 0; //前缀和 
	for (int i=1;i<=n;i++){
		s[i] = s[i-1] + a[i];
	}
	int l=1,r=n;
	while (l < r){ //二分答案 
		bool fl=false;
		int mid = (l+r+1)/2;
		for (int i=mid;i<=n;i++){
			int sum_need = a[i]*mid;
			int sum_before = s[i] - s[i-mid];
			if (sum_need <= sum_before + m){
				fl = true;
				break;
			}
		}
		if (fl){
			l = mid;
		}
		else{
			r = mid-1;
		}
	}
	cout << l;
	return 0;
} 
