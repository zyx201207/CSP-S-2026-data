#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
bool cmp(long long x,long long y){
	return x<y;
}
long long ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long l=1,r=2;
	long long cnt=0;
	while(r<=n){
		cnt=cnt+(a[r]-a[r-1])*(r-l);
		if(cnt<=m){
			ans=max(ans,r-l+1);
		}else{
			while(cnt>m){
				cnt-=(a[r]-a[l]);
				l++;
			}
		}
		r++;
	}
	cout<<ans;
	return 0;
}
