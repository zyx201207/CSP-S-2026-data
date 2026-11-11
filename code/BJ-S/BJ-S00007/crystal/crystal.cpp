#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=1;
	ll cnt=0;
	int l=1,r=2;
	for(;r<=n;r++){
		cnt+=(a[r]-a[r-1])*(r-l);
		while(cnt>m){
			cnt-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
		
	}
	cout<<ans;
	
	return 0;
}
