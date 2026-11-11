//GZ-S00216,彭禹诺，贵阳市第三实验中学 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
ll a[N],t[N],suf[N],pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n-1;i>=1;i--){
		pre[i]=pre[i+1]+a[i];
	}
	ll maxn=1;
	for(int i=n;i>=1;i--){
		ll ans=1,num=a[i],flag=0; 
		int l=1,r=i-1;
		while(l<r){
			ll mid=(l+r)>>1;
			ll knum=pre[l]-pre[i];
			if(a[i]*(i-1-mid+1)-knum<=m){
				flag=1;
				ans=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		if(flag)maxn=max(maxn,i-ans+1); 
	}
	cout<<maxn;
	return 0;
}
/*
8 5
1 1 3 99 99 100 103 200
*/
