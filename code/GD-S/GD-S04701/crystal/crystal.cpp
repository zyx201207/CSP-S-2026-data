#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,ans=0;
bool flag=false;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<ll> a(n+1),c(n+1,0);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
		c[i]=a[i]-a[i-1];
		if(x!=i)flag=true;
	}
	if(!flag){
		ans=(m/2)+1;
		if(m%2!=0)ans+=1;
		cout<<ans;
		return 0;
	}
	sort(a.begin(),a.end());
	ll mx=1;
	for(int i=1;i<=n;i++){
		if(c[mx]<c[i])mx=i-1;
		
	}
	for(int i=mx;i>0;i--){
		if(m-c[i]>=0){
			m-=c[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
