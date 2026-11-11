#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,cnt,now=1,ans=1;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	l=1;r=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	while(r<n){
		r++;cnt+=(a[r]-a[r-1])*now;now++;
		while(cnt>m){
			cnt-=a[r]-a[l];
			l++;
			now--;
		}
		ans=max(now,ans);
	}cout<<ans;
	return 0;
}
