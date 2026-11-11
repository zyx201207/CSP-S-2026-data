/*
因为只有一次合成
排序后，所以我们可以命最后的结果是 ai
对每个ai扫一遍，比ai小的数需要多少次操作才可以使得等于ai
也就是对每个ai
求出一个最大的一个区间 [l,i-1] 
使得 (i-1-l)*ai - sum [l,i-1] <= m
设 fi=(i-1-l)*ai - sum[l,i-1] 
这个如何去做呢
这是一个类似于滑动窗口的东西？
假如我已经知道 i-1 的答案是 li-1
那么是不是 i 的答案就要相比起 i-1 关系式
fi   =     fi-1 + (ai-a[i-1])*(i-l) 
但是有了这个之后新的l 怎么找？【二分】

对啊可以直接二分答案
对于每个 ai，比如我们直接设 x=ai

那么 l=1,r=i- 1
然后获取一个mid之后
如何计算mid能否满足条件？
那肯定就是 a[i]*(i-mid+1)- sum [mid,i]
如果 <=m，那么 r=mid
如果 >m，那么 l=mid+1 
那么能保留最多的数就是  i-mid+1，放入ans取最大 

很对啊！！！！ 
15:00过了！！！！ 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define is insert
#define prq priority_queue
#define gYES cout<<"YES\n";
#define gNO cout<<"NO\n";
#define gYes cout <<"gYes\n";
#define gNo cout<<"gNo\n";
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
#define rf(i,a,b) for(int i=(a);i>=(b);i--)
#define frr(i,a,b) for(int i=(a);i<(b);i++)
const int MOD=998244353;
const int Mod=1e9+7;
const int HASH1=1e7+79;
const int HASH2=5e7+19;
const int N=5e5+5;
void fastIO(){
	ios::sync_with_stdio(0);
	cin.tie(0); cin.tie(0); cout.tie(0);
}int qpow(int x,int y,int mod=MOD){
	int a=1;
	x%=mod;
	while(y){
		if(y&1) a=a*x%mod;
		x=x*x%mod;
		y>>=1;
	}return a;
}int n,m,a[N+5],q[N+5];
int count(int x,int y){
	return (a[y]*(y-x+1)-(q[y]-q[x-1]));
}
void solve(){
	cin >>n >>m;
	fr(i,1,n){
		cin >>a[i];
	}sort(a+1,a+n+1);
	fr(i,1,n) q[i]=q[i-1]+a[i];
	int ANS=0;
	fr(i,1,n){
		int l=1,r=i-1,ans=-1;
		while(l<r){
			int mid=(l+r)>>1;
			int x=count(mid,i);
			if(x<=m) r=mid;
			else l=mid+1;
		}ANS=max(ANS,i-l+1);
		//cout << i-l+1 <<' ';
	}cout <<ANS;
}signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	fastIO();
	int T=1;
	//cin >>T;
	while(T--){
		solve();
	}return 0;
}
