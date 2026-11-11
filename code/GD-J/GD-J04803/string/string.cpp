#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N = 2e5+9;
int a[N];
char c[N];
void brute(){
	string s = "";
	for(int i = 1;i <= n;i++){
		while(a[i]--) s += c[i];
	}
	int ans = 0;
	for(int i = 0;i < s.size() / 2;i++){
		if(s[i] != s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	exit(0);
}
int b[N],pre[N];
char d[N];
int check(char color,int left,int right){
	int l1 = 1,r1 = n,res1 = -1;
	map<char,int> mp;
	while(l1 <= r1){
		int mid1 = (l1 + r1) / 2;
		if(pre[mid1] >= l1) res1 = mid1,l1 = mid1 + 1;
		else r1 = mid1 - 1;
	}
	int l2 = 1,r2 = n,res2 = -1;
	while(l2 <= r2){
		int mid2 = (l2 + r2) / 2;
		if(pre[mid2] < r2) res2 = mid2,r2 = mid2 - 1;
		else l2 = mid2 + 1;
	}
	mp[d[res1]] += (pre[res1] - left + 1);
	mp[d[res2+1]] += (right - pre[res2] + 2);
	for(int i = res1 + 1;i <= res2;i++) mp[d[i]] += b[i];
	int sum = 0;
	for(auto at : mp){
		if(at.first != color) sum += at.second;
	}
	return sum;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin>>n;
	int A = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>c[i];
		b[n-i+1] = a[i];
		d[n-i+1] = c[i];
		A = max(A,a[i]);
	}
	if(A <= 500) brute();

	for(int i = 1;i <= n;i++) pre[i] = pre[i-1] + b[i];
	int ans = 0,l = 1,r = 0;
	for(int i = 1;i <= n;i++){
		r += a[i];
		if(l > pre[n] / 2) break;
		ans += check(c[i],l,r);
		l = a[i] + 1;
	}
	cout<<ans;
	return 0;
}
