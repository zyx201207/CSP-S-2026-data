#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5+5;
int n;
ll m, a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	ll sum = 0; //当前成本
	int l=1, r=2; //[l, r) 已选中
	while(r<=n){
		sum += (a[r]-a[r-1])*(r-1);
		if(sum > m) {
			ll pop=a[r]-a[l], push=(a[r]-a[r-1])*(r-1); //弹出a[l]回收的成本, 加入a[r]的成本;
			if(push < pop){
				l++; r++;
				sum = sum-pop+push;
			} else {
				cout<<r-l;
				break;
			}
		}
		r++;
	}
	return 0;
}
