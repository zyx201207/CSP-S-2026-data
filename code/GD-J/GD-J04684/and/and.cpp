#include<bits/stdc++.h>
using namespace std;
long long n,m,big;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	big = a[n-1];
	for(int i = 0;i < n;i++){
		long long b[m];
		long long bl=0;
		for(int j = 0;j < n && j !=i;j++){
			if(bl+1 <= m){
				b[bl] = a[j];
				bl++;
			}
		}
		long long sth=a[i];
		for(int j = 0;j < m;j++){
			sth &= b[j];
		}
		big=max(big,sth);
	}
	cout << big;
	return 0;
}
