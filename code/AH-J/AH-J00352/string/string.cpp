#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N], ans;
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long len = 0;
	string s;
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		cin>>c[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
		len+=a[i];
	}
	if(len%2){
		long long mid =len/2+1;
		for(int i=mid+1;i<=len;i++) if(s[i-1]!=s[2*mid-i-1]) ans++;
		printf("%lld\n",ans);
	}else{
		long long mid=len/2;
		for(int i=mid+1;i<=len;i++) if(s[i-1]!=s[2*mid-i]) ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
