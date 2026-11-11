#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+5;
int n,p,ans,all; // p 第i个字符相等 
int a[N];
char b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++) {
		cin>>a[i]>>b[i];
		all = all + a[i];
	}
	
	int l = 1, r = n;
	for(int i = 1; i <= n; i++){
		if(l == r) break;
		if(a[l] >= a[r]){
			a[l] -= a[r];
			p += a[r];
			if(b[l] != b[r]) ans += a[r];
			a[r] = 0;
		}else{
			a[r] -= a[l];
			p += a[l];
			if(b[l] != b[r]) ans += a[l];
			a[l] = 0;
		}
		
		if(a[r] == 0) r--;
		if(a[l] == 0) l++;
	} 
	
	cout<<ans;
	return 0;
} 
