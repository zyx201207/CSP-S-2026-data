#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+10;
ll a[maxn];
ll sum[maxn];
ll n,m; 

int f(int l,int w){
	int r=w;
	int mid=(l+r)>>1;
	int ans=0;
	if(sum[r]-sum[mid]<=mid){
		ans=mid;
		l=mid+1;
	}else{
		r=mid-1;
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	if(n==1){
		cout<<1<<'\n';
		return 0;
	}
	sort(a+1,a+1+n);
	
	ll ans=1;
	if(n<=5000){
		for(int i=2;i<=n;i++){
			ll w=m;
			ll cnt=1;
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=w){
					cnt++;
					w-=(a[i]-a[j]);
				}else{
					break;
				}
			} 
			ans=max(ans,cnt);
		}
		
		cout<<ans<<'\n';
		return 0;		
	}else{
		int j=1;
		ll cntb=0;
		for(int i=2;i<=n;i++){

			if(sum[i]<=m){
				cntb=i;
			}else{
				j=f(1,i);
				cntb=j-i+1;
			}
		}
		ans=max(ans,cntb);
	}

	
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

能量水晶666
1.相同的能量值
2.至少m此操作，将那个ai+1，可以选同一个 
3.输出最多能用多少个水晶 合成一个 

思路
1.关于相同，只能增加，那就是怎么增加能让其使用数量最大化
2.就相当于问个最多m个水晶+1后的操作，能让多少个数值达到相同 
3。贪心：先从小的开始加 
*/
