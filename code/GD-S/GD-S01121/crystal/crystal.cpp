#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans;
bool flag1=1,flag2=1;
inline ll find(int mid){
	ll sum=1,v=m;
	for(int i=mid-1;i>=1;i--){
		if(v>=a[mid]-a[i]){
			v-=a[mid]-a[i];
			sum++;
		}
		else break;
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag1=false;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flag2=false;
	}
	sort(a+1,a+n+1);
	if(flag1){
		if(m>n) cout<<n;
		else cout<<m;
	}
	else if(flag2){
		ll minu=a[2]-a[1];
		ll sum=0,cnt=1;
		while(sum<=m) sum+=minu*cnt,cnt++;
		if(cnt-1<=n) cout<<cnt-1;
		else cout<<n;
	}
	else if(n<=5000){
		for(int i=1;i<=n;i++){
			if(find(i)>ans) ans=find(i);
		}
		cout<<ans;
	}
	else{
		int l=1,r=n;
		while(l<=r){
			int mid=l+(r-l)/2;
			if(find(mid)>ans) l=mid+1,ans=find(mid);
			else r=mid-1;
		}
		cout<<ans;
	}
	return 0;
}
