#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;

int n,m,a[N],s[N];

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
	int ans=0;
	for(int r=1,l=1;r<=n;r++){
		while(l<r){
			if((((r-l+1)*a[r])-(s[r]-s[l-1]))>m)l++;
			else break;
		}ans=max(ans,r-l+1);
	}cout<<ans;
	return 0;
}
