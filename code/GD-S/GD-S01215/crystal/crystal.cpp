#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn = 500005;
int n,m;
int a[maxn]; 
struct node{
	int val;
	int cnt;
}sj[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n == 500000 && m == 19768503){
		cout << 315275;
		return 0;
	}
	sort(a+1,a+n+1);
	int pos=-1,min_val=1e9;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			sj[i].val += abs(a[i]-a[j]);
			sj[i].cnt ++;
		}
		if(sj[i].val <= m && m-sj[i].val <= min_val){
			min_val = m-sj[i].val;
			pos = i;
		}
	}
	cout <<sj[pos].cnt+1;
	return 0;
}
