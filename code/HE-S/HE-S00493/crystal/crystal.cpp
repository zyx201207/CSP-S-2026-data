#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	lcout << (a[n]+1)*3+m-9;
	return 0;
}
