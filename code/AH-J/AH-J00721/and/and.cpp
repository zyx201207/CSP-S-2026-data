#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],msum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < m;i++){
		msum += a[i] & msum;
	}
	cout << msum;
	return 0;
}
