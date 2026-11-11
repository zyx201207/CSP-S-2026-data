#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 500005

ll a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;ll m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);

	int l=1,r=1;
	int ans=0;
	for(ll k=0;r<=n;r++,k+=1ll*(r-l)*(a[r]-a[r-1])){
		while(k>m){
			l++;
			k-=a[r]-a[l];
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}
