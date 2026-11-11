#include<bits/stdc++.h>
using namespace std;
long long a[500100];
long long b[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[n+1]=a[n];
	long long ans=0,cnt=0;
	long long l=1,r=1;
	while(r<=n){
		while(cnt>m){
			l++;
			cnt-=(a[r]-a[l-1]);
		}
		ans=max(ans,r-l+1);
		cnt+=(a[r+1]-a[r])*(r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
}
