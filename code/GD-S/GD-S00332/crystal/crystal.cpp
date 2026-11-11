#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int nmax=5e5+5;
ll d[nmax];
ll s[nmax];
ll n,m;
bool check(int mid,int id){
	ll need=1ll*d[id]*(id-mid+1) - (s[id]-s[mid-1]);
	//cout<<mid<<" "<<id<<" "<<need<<"$\n";
	if(need<=m) return 1;
	return 0;
}
int search(int l,int r,int id){
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid,id)){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	sort(d+1,d+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+d[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int pos=search(1,i,i);
		//cout<<i<<" "<<pos<<"\n";
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
}
