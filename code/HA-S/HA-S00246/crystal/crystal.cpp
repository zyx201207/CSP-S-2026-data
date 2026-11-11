#include<bits/stdc++.h>
using namespace std;
long long ns[30000];
long long n,m,cnt=0,ans=0;
bool check(int nn){
	long long cc=0,v=0;
	while(ns[cc]<=nn&&m>=v){
		v+=nn-ns[cc];
		cc++;
	}ans=max(cc,ans);
	if(v>m) return 0;
	else return 1;
}
int erfen(int l,int r){
	while(l<=r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}	
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>ns[i];
	sort(ns,ns+n);
	erfen(ns[0],ns[n-1]);
	cout<<ans;
	return 0;
}
