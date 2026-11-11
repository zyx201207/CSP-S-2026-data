#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pait pair<int,int>
const int N = 2e5+7;
const int M = 21;
const int px = 131;
const int mod = 998244353;
const int Mod = 1e9+7;
int n,mid = 0;
struct node{
	int x; char c;
}a[N];
stack<node>op1;
deque<node>op2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].c;
		mid += a[i].x;
	}
	bool flag = mid % 2;
	mid = (mid + 1) / 2;
	int l = 1,p = 0;
	for(int i=1;i<=n;++i){
		int r = l + a[i].x - 1;
		if(l <= mid && mid <= r){
			p = 1;
			if(!flag){
				if(mid - l + 1 >= 1) op1.push({mid-l+1,a[i].c});
			}
			else if(mid - l >= 1) op1.push({mid-l,a[i].c});
			if(r - mid >= 1) op2.push_back({r - mid,a[i].c});
		}
		else if(p == 0) op1.push({a[i].x,a[i].c});
		else op2.push_back({a[i].x,a[i].c});
		l += a[i].x;
	}
	int sum = 0;
	while(!op1.empty() || !op2.empty()){
		node top1 = op1.top(); op1.pop();
		node top2 = op2.front(); op2.pop_front();
		if(top1.c == top2.c){
			if(top1.x == top2.x) continue;
			else if(top1.x > top2.x) op1.push({top1.x-top2.x,top1.c});
			else op2.push_front({top2.x-top1.x,top2.c});
		}
		else{
			sum += min(top1.x,top2.x);
			if(top1.x == top2.x) continue;
			else if(top1.x > top2.x) op1.push({top1.x-top2.x,top1.c});
			else op2.push_front({top2.x-top1.x,top2.c});
		}
	}
	cout<<sum<<endl;
	return 0;
}
