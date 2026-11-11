/*min ans1 ans2打成max
被自己蠢哭了
awa*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5 + 10;
int n;
long long a[MAXN],aa[MAXN];
long long c[MAXN],cc[MAXN];
long long pre[MAXN];
long long sur[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i ++){
		char tmp;
		cin>>a[i]>>tmp;
		aa[i] = a[i];
		c[i] = tmp - 'a' + 1;
		cc[i] = c[i];
		pre[i] = pre[i-1] + a[i];
 	}
 	int mid = pre[n] / 2 + (pre[n] & 1 == 1);
 	int pr = upper_bound(pre+1,pre+n+1,mid) - pre;
 	int ms = mid - pre[pr - 1];
 	if(ms != 0){
 		for(int i = pr;i <= n+1;i ++){
 		if(i == pr){
 			a[pr] = ms;
 			a[pr+1] = aa[pr] - ms;
 			c[pr+1] = c[pr];
 			i++;
		}
		else{
			a[i] = aa[i-1];
			c[i] = cc[i-1];
		}
	 }
	}
	n = n + (ms != 0);
	int ans1 = 0,ans2 = 0,cnt = 0;
	//左 -> 右
	int l = 1,r = n;
	while(l+1 < r){
		while(a[l] - a[r] >= 0){
			a[l] -= a[r];
			if(c[l] != c[r]) cnt += a[r]; 
			r --; 
			
		}
		a[r] -= a[l];
		if(c[l] != c[r]) cnt += a[l];
		l ++;
	}
	ans1 = cnt;
	//右 -> 左 
	 l = 1;r = n;
	 cnt = 0;
	while(l+1 < r){
		while(a[r] - a[l] >= 0){
			a[r] -= a[l];
			if(c[l] != c[r]) cnt += a[l]; 
			l --; 
			
		}
		a[l] -= a[r];
		if(c[l] != c[r]) cnt += a[r];
		r --;
	} 
 	ans2 = cnt;
 	cout<<min(ans1,ans2);
}
