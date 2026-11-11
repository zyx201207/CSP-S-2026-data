#include <bits/stdc++.h>
using namespace std;
long long a[100005],n,m;
int dsj(){
	for(long long i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			return i-1;
		}
	}
	return n;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (long long i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	long long s=0;
	for(long long i=0;i<m;i++){
		a[1]++;
		for(long long j=2;j<=n;j++){
			if(a[j-1]<=a[j]){
				break;
			}
			swap(a[j-1],a[j]);
		}
		long long x=dsj();
		if(x==n){
			cout << x;
			return 0;
		}
		s=max(s,x);
	}
	cout << s;
	return 0;
}
//1 2 4 8 9
//2 2 4 8 9 1
//3 2 4 8 9 2
//2 3 4 8 9
//3 3 4 8 9 3
//4 3 4 8 9 4
//3 4 4 8 9
//4 4 4 8 9 5
