#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;

int n,m;
int a[N];


int ans1;
void dfs1(int now,int cnt,int res) {
	if(cnt >= m) {
		ans1=max(ans1,res);
		return;
	}
	if(now > n) return;
	dfs1(now+1,cnt+1,(res & a[now]));
	dfs1(now+1,cnt,res);
	return;
}
void solve1() { // O(2^m)
	dfs1(1,0,INT_MAX);
	cout<<ans1<<endl;
	return;
}


void solve2() { // O(n)
	int ans2=INT_MAX;
	for(int i=1;i<=n;i++) {
		ans2 &= a[i];
	}
	cout<<ans2;
	return;
}


void solve3() { // O(n)
	// m = n-1
	vector<int>front(n+1, INT_MAX);
	vector<int>back(n+2, INT_MAX);
	int ans=0;
	for(int i=1;i<=n;i++) {
		front[i] =  front[i-1] & a[i];
	}
	for(int i=n;i>=1;i--) {
		back[i] =  back[i+1] & a[i];
	}
	for(int i=1;i<=n;i++) {
		ans = max(ans, front[i-1] & back[i+1]);
	}
	cout<<ans;
	return;
}


bool cmpA(int x,int y) {
	return x > y;
}
void solveA() {
	// a[i] = 0001111...111
	sort(a+1,a+1+n,cmpA);
	int ans = INT_MAX;
	for(int i=1;i<=m;i++) {
		ans &= a[i];
	}
	cout<<ans;
	return;
}


int lowbit(int x) {
	return (((x-1)^x)+1)>>1;
}

void solve4() {
	// a max < 4
	int ans=0;
	// 要第一位 01
	int cnt1=0;
	for(int i=1;i<=n;i++) {
		if(a[i] == 1 || a[i] == 3) {
			cnt1++;
		}
	}
	if(cnt1 >= m) {
		ans = 1;
	}
	// 要第二位 10
	int cnt2=0;
	for(int i=1;i<=n;i++) {
		if(a[i] > 1) {
			cnt2++;
		}
	}
	if(cnt1 >= m) {
		ans = 2;
	}
	// 都要 11 
	int cnt3=0;
	for(int i=1;i<=n;i++) {
		if(a[i] == 3) {
//			cout<<'i'<<i<<endl;
			cnt3++;
		}
	}
	if(cnt3 >= m) {
		ans = 3;
	}
	cout<<ans;
	return;
}


int Max;
void solve5() {
	int ans=0;
	for(int aim=1;aim<=Max;aim++) {
		int cnt=0;
		for(int i=1;i<=n;i++) {
//			cout<<a[i]<<'&'<<aim<<'='<<(a[i] & aim)<<endl;
			if((a[i] & aim) == aim) {
				cnt++;
			}
			if(cnt == m) break;
		}
//		cout<<aim<<' '<<cnt<<endl;
		if(cnt>=m) {
			ans = aim;
//			cout<<"yes"<<endl;
		}
	}
	cout<<ans;
	return;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		Max = max(Max,a[i]);
	}
	if(m == n) {
		solve2();
	}
	else if(n <= 2000) {
		solve1();
	}
	else if(m == n-1) {
		solve3();
	}
	else if(Max < 4) {
		solve4();
	}
	else if(Max < (1 << 10)) {
		solve5();
	}
	else {
 		solveA();
	}
	return 0;
}
