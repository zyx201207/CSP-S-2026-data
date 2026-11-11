#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],s[500005];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=1;
	while(r<n){
		if(a[r+1]*(r+1-l+1)-s[r+1]+s[l-1]<=m){
			r++;
			ans=max(ans,r-l+1);
		}
		else{
			l++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
