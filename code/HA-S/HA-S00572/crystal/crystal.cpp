#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],hd=1,ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	ll sum=0;
	for(ll i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-hd);
		while(sum>m&&hd<=i){
			sum-=a[i]-a[hd];
			hd++;
		}ans=max(ans,i-hd+1);
	}cout<<ans;
	return 0;
}
