#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
vector<long long> a;
ll w,k;
ll r=0,l,sp,ans=0;

long long re(){
	cin>>n>>m;
	w=m;
	for(ll i=0;i<n;i++){
		ll p;
		cin>>p;
		a.push_back(p);
	}
	sort(a.begin(),a.end());
	sp=a[0];
	while(a[r]*(r-l+1)-sp<=w&&r<n){
		r++;
		sp+=a[r];		
	}
	sp-=a[r];
	r--;
	ans=r+1;
	for(l=0;r<n&&l<=r;){ 
		if(a[r]*(r-l+1)-sp<=w&&l<n&&r<n){
			while(a[r]*(r-l+1)-sp<=w&&l<n&&r<n){
				r++;
				sp+=a[r];
			}
			sp-=a[r];
			r--;
			int y=a[l-1];
			ans=max(r-l+1,ans);
			if(l>=1){
				if(a[r]*(r-l+1)-sp+(a[r]-a[l-1])<=w){
					ans++;
					l--;
				}	
			}
		}
		l++,r++;
		sp=sp-a[l-1]+a[r];
	}
	return ans;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ll mpk=re();
	cout<<mpk;
	return 0;
}
