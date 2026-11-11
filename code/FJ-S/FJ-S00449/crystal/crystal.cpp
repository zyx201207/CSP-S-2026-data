#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define mn 500005
using namespace std;
long long n,m,a[mn],l,ans;
__int128 s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	l=1;
	for(int r=1;r<=n;r++){
		s+=(r-l)*(a[r]-a[r-1]);
		while(s>m){
			s-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
