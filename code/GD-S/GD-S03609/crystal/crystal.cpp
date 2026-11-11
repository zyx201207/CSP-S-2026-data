#include<bits/stdc++.h>
#define N 500010
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define lowbit(x) (x&-x)
using namespace std;
int n;
ll m,sum,a[N];
int q[N],*front,*tail;
int main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i)cin >> a[i];
	sort(a+1,a+n+1);
	// slipping windows
	front = tail = q;// max
	int l = 1;// last ont in q
	int ans = 1;
	for(int i = 1;i <= n;++i){
		sum += a[i];
		while(front != tail && a[*(tail-1)] < a[i])--tail;
		*(tail++) = i;
		while(front != tail && l < i && (i-l+1)*a[*front] > m + sum){
			sum -= a[l];
			++l;
			while(*front < l)++front;
		}
		ans = max(ans,i-l+1);
	}
	cout << ans;
	return 0;
} 
/*
5 8
-3 -1 2 2 7



*/
