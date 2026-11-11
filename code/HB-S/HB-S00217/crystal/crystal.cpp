#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll ans=0;
ll b[500005];

bool checkB(){
	
	ll g=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(a[i+1]-a[i]!=g){
			return 0;
		}
	}
	
	return 1;
}

void runningA(){
	for(int i=1;i<=n;i++){
		ll cnt=0;
		for(int j=i-1;j>=1;j--){
			cnt+=a[i]-a[j];
		}
		if(cnt<=m){
			ans=i;
		}else{
			break;
		}
	}
	
	cout<<ans;
	return ;
}

void runningB(){
	ll g=a[2]-a[1];
	
	b[1]=0;
	ans=1;
	
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+g*(i-1);
		if(b[i]<=m){
			ans=i;
		}else{
			break;
		}
	}
	cout<<ans;
	return ;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n);
	
	if(checkB()){
		runningB();
	}else{
		runningA();
	}
	return 0;
}
