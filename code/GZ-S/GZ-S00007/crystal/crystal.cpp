//GZ-S00007 安顺市第一高级中学 徐陈乾康 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define rt return
#define ll long long
const ll MAXN=1e18+7;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=0,tot=0,T;
	vector<ll>a(2*n);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>m;
	for(ll i=1;i<n+1;i++){
		cin>>a[i];
	}
	T=a[n]-a[n-1];
	for(int i=1;i<MAXN;i++){
		tot+=i;
		if(tot*T<=m){
			ans++;
		}
		else break;
	}
	cout<<ans+1;
	rt 0;
}

//也许 普及 
