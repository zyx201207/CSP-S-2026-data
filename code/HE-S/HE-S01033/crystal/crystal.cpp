#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(ll i=1;m>0&&i<=n;i++){
		for(ll j=i-1;j>0&&m>0;j--){
			if(m-(a[i]-a[j])>=0){
				m-=a[i]-a[j];
				a[j]=a[i];
			}
		}
	}
	ll cnt=1;
	for(ll i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			ans=max(cnt,ans);
			cnt=0;
		}
		cnt++;
	}cout<<max(cnt,ans);
	return 0;
}
