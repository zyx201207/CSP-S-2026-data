#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n;
int T;
string s;
char tmp;
int ans;
int vis[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	int vv=0;
	while(T--){
		vv++;
		cin>>n>>tmp;
		vis[vv]=n;
		s+=tmp;
	}
	s=" "+s;
	int l=1;
	int r=vv;
	while(l<=r){
		if(vis[l]>vis[r] and s[l]==s[r]){
			vis[l]-=vis[r];
			r--;
			continue;
		}
		if(vis[l]>vis[r] and s[l]!=s[r]){
			ans+=vis[r];
			vis[l]-=vis[r];
			r--;
			continue;
		}
		if(vis[l]<vis[r] and s[l]==s[r]){
			vis[r]-=vis[l];
			l++;
			continue;
		}
		if(vis[l]<vis[r] and s[l]!=s[r]){
			ans+=vis[l];
			vis[r]-=vis[l];
			l++;
			continue;
		}
		if(vis[l]==vis[r] and s[l]==s[r]){
			l++;
			r--;
			continue;
		}
		if(vis[l]==vis[r] and s[l]!=s[r]){
			ans+=vis[l];
			l++;
			r--;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
