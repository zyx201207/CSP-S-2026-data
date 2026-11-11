#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const ll MAXN=5e5+5;
ll n,m,a[MAXN],cha[MAXN];
bool tepan1=true,tepan2=true;
ll cal(ll l,ll r){
	ll res=0,cnt=0;;
	for(int i=r-1;i>=l;--i){
		res+=(cha[i]*(r-l-cnt));
		cnt++;
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=i){
			tepan1=false;
		}
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			tepan2=false;
		}
	} 
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		cha[i-1]=(a[i]-a[i-1]);
	}
	if(n<=5000){
		ll ans=1;
		for(int i=1;i<=n;++i){
			ll l=1,r=i,anss=i;
			while(l<=r){
				ll mid=(l+r)>>1;
				ll cur=cal(mid,i);
				if(cur<=m){
					r=mid-1;
					anss=mid;
				}
				else{
					l=mid+1;
				}
			}
			ans=max(ans,i-anss+1);
		}
		cout<<ans; 
	}
	else if(tepan1){
		ll l=1,r=n,anss=1;
		while(l<=r){
			ll mid=(l+r)>>1;
			if((mid-1+1)*(mid-1)/2<=m){
				anss=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		cout<<anss;
	}
	else if(tepan2){
		ll l=1,r=n,anss=1;
		ll gongcha=a[2]-a[1];
		while(l<=r){
			ll mid=(l+r)>>1;
			if((mid-1+1)*(mid-1)/2*gongcha<=m){
				anss=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		cout<<anss;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
