#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int N = 5e5 + 110;
long long a[N];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	sort(a+1,a+n+1);
	
	int l = 0 , r = n + 1;
	
	while(l+1<r){
		int mid = (l + r) / 2;
		long long res = 0;
		for(int i=1;i<mid;i++){
			res += (a[mid] - a[i]);
		}
		if(res <= m){
			l = mid;
		}
		else r = mid;
	}
	
	cout << l;
	
	return 0;
}
