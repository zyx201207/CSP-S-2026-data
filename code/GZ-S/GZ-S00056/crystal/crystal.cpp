//GZ-S00056,彭翊瑄，北师大贵阳附中 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vl vector<ll>
#define pll pair<ll,ll>
#define fi first
#define se second
void ji(){
	ll n,m;
	cin>>n>>m;
	vl a(n+1),diff(n+1);
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(ll i=1;i<n;i++){
		diff[i]=a[i+1]-a[i];
	} 
	ll maxn=0,need=0,ans=0;
	ll l,r;
	for(ll i=1;i<=n;i++){
		if(diff[i]<=m){
			l=i;
			r=i+1;
			need=diff[i];
			maxn=2;
			break;
		}
	}
	while(r<=n){
		if(need+diff[r]<=m){
			r++;
			if(r>n)break;
			need+=diff[r];
			maxn++;
			ans=max(ans,maxn);
		}
		else{
			while(need+diff[r]>m){
				l++;
				maxn--;
				need-=diff[l];
			} 
		}
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll t=1;//cin>>t;
	while(t--){
		ji();
	}
	return 0;
} 
