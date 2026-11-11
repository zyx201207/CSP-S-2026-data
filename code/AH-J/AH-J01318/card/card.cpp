#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
const ll M=3e5+5;
ll n,m,tsxzA=1;
ll a[N],t[M],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]) tsxzA=0;
		ans[a[i]]++;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(tsxzA){
		for(ll i=1;i<=m;i++){
			ans[i]+=ans[i-1];
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(ll i=1;i<=m;i++) ans[i]=0;
	for(ll lun=1;lun<=n;lun++){
		for(ll i=1;i<=n;i++) t[a[i]]=0;
		for(ll i=lun,r=lun;i<=n;i++){
			if(t[a[i]]){
				for(ll j=t[a[i]]+1;j<=r;j++) t[a[j]]=0;
			} 
			r=t[a[i]]=i;
		}
		for(ll i=1;i<=m;i++) ans[i]+=(t[i]!=0);
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
