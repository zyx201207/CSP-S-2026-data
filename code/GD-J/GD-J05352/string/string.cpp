#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[10000000001],cnt=0;
	string c,s;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=1;i*2<=s.size()-1;i++){
		if(s[i]!=s[n-i+1]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
