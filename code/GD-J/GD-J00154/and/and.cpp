#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	long long M=-2e9;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		M=max(M,a[i]);
	}
	if(m==1){
		cout << M << endl;
		return 0;
	}
	if(n==m){
		long long x=a[1];
		for(int i=2;i<=n;i++){
			x&=a[i];
		}
		cout << x << endl;
		return 0;
	}
	long long Max=-2e9;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			Max=max(Max,a[i]&a[j]);
		}
	}
	cout << Max << endl;
	return 0;
}
