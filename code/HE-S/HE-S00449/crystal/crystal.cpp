#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500001]={},cnt,l=1,r=1,ma=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	while(1){
		r++;
		cnt+=(a[r]-a[r-1])*(r-l);
		while(cnt>m){
			if(l==r)break;
			cnt-=a[r]-a[l-1];
			l++;
		}if(cnt<=m)ma=max(ma,r-l+1);
		if(r==n)break;
	}cout<<ma;
	return 0;
}
