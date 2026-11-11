#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long d[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	long long maxx=-1,cnt=0,r=n,cnt1=0;
	for(int i=n;i>=1;i--){
		cnt+=d[i];
		cnt1+=cnt;
		if(cnt1>m){
			maxx=max(maxx,r-i+1);
		}
		while(cnt1>m){
			cnt-=d[r];
			cnt1-=(r-i+1)*d[r];
			r--;
		}
		
	}
	maxx=max(maxx,r); 
	cout<<maxx;
	return 0;
} 
