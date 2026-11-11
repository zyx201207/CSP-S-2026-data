#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL const MAXN = 1e6 + 10;

LL n, m, ans = 0, rec = 0;
LL a[MAXN];
LL bix[MAXN];
LL fx[MAXN];

LL Cal(LL x){
	return (rec ^ x) & (x & (rec ^ ((1 << 31) - 1)));
}

bool cmp(LL a, LL b){
	return Cal(a) < Cal(b);
}


int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	bix[0] = 1;
	cin >> n >> m;
	for(int i = 1; i <= 31; i++)
		bix[i] = (1 << i);
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
		
	
	
	LL top = n;
	sort(a + 1, a + top + 1);
	
	for(int j = 30; j >= 0; j--){
		if(a[m] & bix[j]){
			LL l = m, r = top;
			while(l < r){
				LL mid = (l + r + 1) / 2;
				if(a[mid] & bix[j])l = mid;
				else r = mid - 1;
			}
			top = l;
			ans = ans | bix[j];
			sort(a + 1, a + top + 1, cmp);
		}
		rec |= bix[j]; 
	}
	
	cout << ans << '\n';
	
	
	
	return 0;
}


