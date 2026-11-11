#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2*1e5 + 101;
int n,m,p,maxn,a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	if(m==1){
		for(int i=1;i<=n;i++)
			if(maxn < a[i])
				maxn = a[i];
		cout << maxn;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			p = a[i] & a[j];
			if(p>maxn) maxn = p;
			cout << maxn << "\n"; 
		}
	}
	cout << "\n" << maxn;
	return 0;
}
/*
4
*/
