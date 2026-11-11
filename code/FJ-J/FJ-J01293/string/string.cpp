#include <bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long t=0;
	cin >> n;
	a+=' ';
	for(int i=1;i<=n;i++){
		int a1;
		char b;
		cin >> a1 >> b;
		int c=int(b-'a'+1);
		for(int j=1;j<=a1;j++){
			a+=b;
		}
		t+=a1;
	}
	long long ans=0;
	for(long long i=1;i<=t/2+t%2;i++){
		if(a[i]!=a[t-i+1]) ans++;
	}
	cout << ans;
	return 0;
}
