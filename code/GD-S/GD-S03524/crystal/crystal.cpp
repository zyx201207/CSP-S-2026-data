#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10,ANS=315275;
ll a[N],n,m,ans=0,rp=4e18;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll L=1,cost=0,len=0;
	for(ll R=1;R<=n;R++){
		cost+=(a[R]-a[R-1])*(R-L);
		while(1){
			if(cost<=m) break;
			cost-=(a[R]-a[L]),L++;
		}
		ans=max(ans,R-L+1);
		//cout<<R<<' '<<L<<'\n';
	}
	cout<<ans;
	return 0;
} 
//对于第x个数，选择它左边井可能大的数，枚举，它能要几个数是可以算出来的 
//求你了别挂分qwq
//rp++ 我要7勾！ 
