#include<bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for(ll i=j;i<k;i++)
#define ll long long

int n;
ll ina[500007],m,t1,ans1=1,t2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	FOR(i,1,n+1){
		cin>>ina[i];
	}
	sort(ina+1,ina+1+n);
	FOR(i,1,n+1){
		ina[i]+=ina[i-1];
	}
	FOR(i,1,n+1){
		t1=ina[i]-ina[i-1];
		ll l=0,r=i-1,mid,ans;
		while(l<=r){
			mid=(l+r)>>1;
			t2=(i-mid)*t1-ina[i]+ina[mid];
			if(t2>m){
				l=mid+1;
			}else{
				ans=mid;
				r=mid-1;
			}
		}
//		cout<<ina[i]<<' '<<t1<<' '<<ans<<" q11\n";
		ans1=max(ans1,i-ans);
	}
	cout<<ans1;
	return 0;
} 
