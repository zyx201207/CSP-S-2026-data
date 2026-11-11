#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[2005],num;
string s,all;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	
	if(n==1){
		cout << 0;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==1){
			cout << n/2;
			return 0;
		}
	}

	
	
	
	return 0;
}
