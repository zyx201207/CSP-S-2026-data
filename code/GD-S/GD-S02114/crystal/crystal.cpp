#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=5e5+10;
ll a[maxn],he[maxn],cha[maxn],ans[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	ll m;
	cin>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			flag=false;
		}
	}
	if(flag){
		ll ans=1;
		for(int i=2;i<=n;i++){
			ll s=(1+i-1)*(i-1)/2;
			if(s<=m){
				ans=i;
			}
		}
		cout<<ans;
		
		return 0;
	}
	sort(a+1,a+n+1);
	bool st=true;
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		he[i]=he[i-1]+cha[i];
	}
	for(int i=3;i<=n;i++){
		if(cha[i]!=cha[i-1]){
			st=false;
		}
	}
	if(st){
		ll ans=1;
		for(int i=2;i<=n;i++){
			ll s=(cha[i]+(i-1)*cha[i])*(i-1)/2;
			if(s<=m){
				ans=i;
			}
		}
		cout<<ans;
		
		return 0;
	}
	ans[1]=1;
	for(int i=2;i<=n;i++){
		ll cnt=m;
		for(int j=i;j>=1;j--){
			ll k=he[i]-he[j];
			if(cnt>=k){
				ans[i]+=1;
				cnt-=k;
			}
		}
	}
	ll out=0;
	for(int i=1;i<=n;i++){
		out=max(ans[i],out);
	}
	cout<<out;
	
	return 0;
} 
