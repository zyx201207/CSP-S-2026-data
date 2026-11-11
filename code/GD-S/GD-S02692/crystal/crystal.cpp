#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,nm=0,cnt=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	long long he=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		nm+=(a[i]-a[i-1])*(i-he),cnt++;
		if(nm<=m) ans=max(ans,cnt);
		else{
			while(nm>m){
				nm-=(a[i]-a[he]);
				he++,cnt--;
				if(nm<=m) break;
			}
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
	return 0;
}
