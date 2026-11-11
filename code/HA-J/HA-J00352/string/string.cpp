#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
long long a[MAXN];
char c[MAXN];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long midd = 0;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	long long mid = (midd+1)/2;
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int ans = 0;
	if(midd % 2 == 1){
		int ans1 = 0;
		int ans2 = 0;
		for(int i=1,j = n;i<=mid-1,j>=mid+1;i++,j--){
			if(s[i] == s[j]) continue;
			if(s[i]!= s[j]) ans1++;
			if(s[j]!= s[i]) ans2++;
		}
		ans  = min(ans1,ans2);
	}
	else{
		int ans1 = 0;
		int ans2 = 0;
		for(int i=1,j = n;i<=mid,j>=mid+1;i++,j--){
			if(s[i] == s[j]) continue;
			if(s[i]!= s[j]) ans1++;
			if(s[j]!= s[i]) ans2++;
		}
		ans  = min(ans1,ans2);
	}
	cout << ans;
	return 0;
}