#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,m,ans;
ll a[200010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(n<=30){
		for(ll i=1;i<=(1<<n);i++){
			ll cnt=0,temp=0;
			int x=i;
			for(ll j=1;j<=n;j++){
				if((x>>(j-1))&1){
					if(cnt==0) temp=a[j];
					else temp&=a[j];
					cnt++;
				}
			}
			if(cnt!=m) continue;
			else ans=max(ans,temp);
		}
	}else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}else if(m==n){
		for(int i=1;i<=n;i++){
			if(i==1) ans=a[i];
			else ans&=a[i];
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	cout<<ans;
	
	return 0;
}
