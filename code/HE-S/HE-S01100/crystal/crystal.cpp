#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+6;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1,cnt=0,l=1;
	for(int i=2;i<=n;i++){
		int k=a[i]-a[i-1];
		cnt+=k*(i-l);
		if(cnt<=m) ans=max(i-l+1,ans);
		else if(cnt>m){
			while(cnt-(a[i]-a[l])>m&&i>l){
				cnt-=(a[i]-a[l]);
				l++;
			}if(cnt-(a[i]-a[l])<=m&&i>l){
				ans=max(i-l,ans);
				cnt-=(a[i]-a[l]);
				l++;
			}
		}
	}cout<<ans;
	
	return 0;
}
