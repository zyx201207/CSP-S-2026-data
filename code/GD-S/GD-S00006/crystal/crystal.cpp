#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	vector<ll>a(n+1);
	vector<ll>b(n+1);
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;++i)b[i]=a[i]-a[i-1];
	b[1]=0;
	ll l=1,cnt=0,ans=0,a1=0;
	for(int r=1;r<=n;++r){
		cnt+=b[r]*a1;
		a1++;
		if(cnt>m){
			ans=max(ans,a1-1);
			cnt-=a[r]-a[l];
			l++,a1--;
		}
	}
	cout<<ans<<"\n";
	return 0;
} 
