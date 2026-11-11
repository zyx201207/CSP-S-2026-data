#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1,ans=0;
	ll cnt=0;
	while(r<n){
        while(cnt<=m && r<n){
            cnt+=(a[r+1]-a[r])*(r-l+1);
            r++;
            if(cnt<=m) ans=max(ans,r-l+1);
        }
        while(cnt>m){
            cnt-=a[r]-a[l];
            l++;
            if(cnt<=m) ans=max(ans,r-l+1);
        }
        ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
