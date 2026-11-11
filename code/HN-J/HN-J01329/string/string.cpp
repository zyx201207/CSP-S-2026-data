#include<bits/stdc++.h>
#define N 100005
using namespace std;
long long n,ans = 0,c = 1,l,r,mn;
long long a[N];
char s[N];
void work(){
	while(l != r){
		mn = min(a[l],a[r]);
		a[l] -= mn;
		a[r] -= mn;
		if(s[l] != s[r]) ans += mn;
		if(a[l] == 0) l++;
		else r--;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	l = 1,r = n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		cin >> s[i];
	}
	work();
	cout << ans << endl;
	return 0;
}
