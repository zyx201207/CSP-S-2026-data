#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lc(i) ((i)<<1)
#define rc(i) ((i)<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
constexpr int N=5e5+5;
int n;
ll m,a[N],pre[N];
// 尝试合成 a[l..r] 
bool check(ll k,int l,int r){
	const ll s1=pre[r]-pre[l-1];
	const ll s2=k*(r-l+1);
	return s2-s1<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int lb=1,ub=i+1;
		while(ub-lb>1){
			int mid=(lb+ub)>>1;
			if(check(a[i],i-mid+1,i))lb=mid;
			else ub=mid; 
		}
		ans=max(ans,lb);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
设最终用于合成的水晶能量为 k
则 k 一定是 a[1..n] 中的一个
先从小到大排序 
枚举 a[i]=k 
则可能参与合成的水晶为 a[1..i]
二分能合成多少颗水晶 
不开 long long 见祖宗！ 

5 4
1 -3 0 -1 -2 

*/ 
