#include<bits/stdc++.h>
using namespace std;
#define int long long
using namespace std;
inline int read(){
	int res = 0,l = 1;char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-')l = -1;
		ch = getchar();
	}
	while(isdigit(ch))res = res * 10 - '0' + ch,ch = getchar();
	return res * l;
}
const int N = 5e5 + 10;
int n,m,a[N],cnt[N];
deque<int> dq;
bool check(int x){
	while(!dq.empty())dq.pop_front();
	for(int i = 1;i <= n;i++){
		while(!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
		if(!dq.empty() && dq.front() < i - x)dq.pop_front();
		dq.push_back(i);
		if(i < x)continue;
		int sum = cnt[i] - cnt[i - x];
		//cout << x << " " << a[dq.front()] << " " << sum << "\n";
		if(sum + m >= a[dq.front()] * x)return true;
	} 
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i++)a[i] = read();
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)cnt[i] = cnt[i - 1] + a[i];
	int l = 1,r = n;
	while(l <= r){
		int mid = ((l + r) >> 1);
		if(check(mid))l = mid + 1;
		else r = mid - 1;
	}
	cout << r;
	return 0;
}
