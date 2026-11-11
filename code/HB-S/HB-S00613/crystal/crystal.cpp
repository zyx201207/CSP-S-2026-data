#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,sum;
long long a[500002],s[500002];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum+=a[n]-a[i];
    if(sum<=m){cout<<n;return 0;}
    long long l=1,r=1,cnt=0;
    while(r<=n && l<=r){
		while(cnt>m && l<=r){
			cnt-=a[r]+a[l];
			l++;
			ans=max(ans,r-l+1);
		}
		while(cnt<=m && r<=n){
			r++;
			if(r>n) break;
			cnt+=(a[r]-a[r-1])*(r-l);
		}
	}
	cout<<ans;
	return 0;
} 
