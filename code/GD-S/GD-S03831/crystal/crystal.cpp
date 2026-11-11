#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[500010];
int pre[500010];
int diff[500010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	a[0] = a[1];
	for(int i = 1;i <= n;i ++){
		diff[i] = a[i] - a[i-1];
		pre[i] = diff[i-1] + diff[i];
	}
	int ans = -1;
	int cnt = -1;//左边拿上cnt颗宝石 
	int ms = 0;//需要+1的总和次数 
	int zh = 0;//路径总和，用于扔下左侧的宝石 
	int pos = 0;//已经扔下第pos颗宝石了 
	for(int i = 1;i <= n;i ++){
//		cout << "检索第" << i << "颗宝石\n"; 
		cnt++;
		ms += diff[i]*cnt;
		zh += diff[i];
//		cout << "拿第" << i-1 << "颗，检查有没有超过代价\n";
//		cout << "此刻代价为" << ms << '\n';
		if(ms > m){
//			cout << "超过代价，踢宝石\n";
			while(ms > m){
				cnt--;
				ms -= zh;
				pos++;
				zh -= diff[pos+1];
//				cout << "踢掉一颗，路径总和变为" << zh << '\n';
//				cout << "现在代价数量为" << ms << '\n';
			}
		}
//		cout << "最终本轮合法代价为" << ms << '\n';
		ans = max(cnt,ans);
	}
	cout << ans+1;
	return 0;
} 
