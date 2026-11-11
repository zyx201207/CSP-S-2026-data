#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500001];
long long ans;
long long fir[500001];
bool check(long long mid){
	long long cnt=1e18;
	for(int l=1,r=mid;r<=n;l++,r++){
		cnt=min(cnt,fir[r]-fir[l-1]-mid*(a[n]-a[r]));
	}
	return cnt<=m;
}
long long l,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	l=0,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		fir[i]=fir[i-1]+(a[n]-a[i]);
	}
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
} 
