#include<bits/stdc++.h>
using namespace std;
string q;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	long long len=-1;
	for(long long i=1;i<=n;i++){
		long long a;
		char b;
		cin >> a >> b;
		len+=a;
		for(long long j=1;j<=a;j++){
			q += b;
		}
	}
	for(long long i=0;i<=len/2;i++){
		if(q[i] != q[len-i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
