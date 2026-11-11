#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,l,r,ans,a[N],cnt;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ans=1,l=1,cnt=0;
	for(int r=2;r<=n;r++){
		cnt+=(r-l)*(a[r]-a[r-1]);
//		cout<<cnt<<' ';
		while(cnt>m) cnt-=a[r]-a[l],l++;
//		cout<<cnt<<' ';
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
