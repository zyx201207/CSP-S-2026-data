#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans;
ll a[500005],p[500005],m;
bool check(int st,int mid){
	ll cnt=0;
	for(int i=st;i<=mid;i++){
		cnt+=a[mid]-a[i];
	}
	return cnt<=m;
}
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	stable_sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		p[i]=a[i+1]-a[i];
	}
	bool io=1;
	for(int i=1;i<n-1;i++){
		if(p[i]!=p[i+1]) io=0;
	}
	if(io){
//		cout<<100000;
		ll cnt=0;
		for(int i=1;i<n;i++){
			cnt+=i*p[i];
//			cout<<cnt<<endl;
			if(cnt>m){
				ans=i;
				break;
			}
		}
		if(!ans) ans=n;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(i,mid)){
				ans=max(ans,mid-i+1);
				l=mid+1;
			}
			else r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
????????
*/
