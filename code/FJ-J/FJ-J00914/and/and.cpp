#include <bits/stdc++.h>
using namespace std;

int main(){
	//记得取消注释 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	long long n,m;
	cin >> n >> m;
    long long a[n+5]={ };
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	} 
	cout << a[n]; 
	return 0;
} 
