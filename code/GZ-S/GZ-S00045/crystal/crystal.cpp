//GZ-S00045 王子晨 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int,int>
#define pri priority
#define vec vector

#define rep(i,low,up) for(int i=low;i<=up;i++)
#define per(i,up,low) for(int i=low;i<=up;i++)

/*
thinking
已深度思考 114514s 
>-<
:-) 
ddl: 16：36

running:
AC：
读入ai并排序
从前往后把每个数选为调整目标
借助前缀和查找区段和，快速求出预估差值=元素个数x调整目标-区间和
双指针扫描区间：超出m左收缩，不足m右扩张 
*/

const int N=5e5+3;

ll n,m,ans;
vec<ll> a(N),pre(N);
ll i,j;

void solve(){
	cin>>n>>m;
	
	rep(i,1,n){
		cin>>a[i];
	}
	
	sort(a.begin()+1,a.begin()+n+1);
	
	rep(i,1,n){
		pre[i]=pre[i-1]+a[i];
	}
	
	ll t;
	j=1; 
	rep(i,1,n){
		t=a[i]*(i-j+1)-pre[i]+pre[j-1];
			if(t<=m){
				ans=max(ans,(ll)i-j+1);
			}else{
				j++;
			}
	}
	cout<<ans;
	return;
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t=1;
//	cin>>t;
	while(t--){
		
		solve();
	}
	return 0;
}
