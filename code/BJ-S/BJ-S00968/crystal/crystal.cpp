#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,k,ans;
int main(){
	freopen("crystal1.in","r",stdin);
	freopen("crystal1.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	k = a[2] - a[1];
	m /= 2;
	int i = 1;
	while(m > i){
		m -= i;
		i += k;
	}
	cout << i - k;
	return 0;
}