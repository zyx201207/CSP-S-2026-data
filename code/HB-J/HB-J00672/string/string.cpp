#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,mp[200005][3],ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&mp[i][1]);
		char temp;
		cin>>temp;
		mp[i][2]=temp-'a';
	}
	int l=1,r=n;
	while(l<=r){
		if(mp[l][1]<mp[r][1]){
			if(mp[l][2] != mp[r][2]){
				ans+=mp[l][1];
			}
			mp[r][1]-=mp[l][1];
			l++;
		}
		else if(mp[l][1]>mp[r][1]){
			if(mp[l][2] != mp[r][2]){
				ans+=mp[r][1];
			}
			mp[l][1]-=mp[r][1];
			r--;
		}
		else if(mp[l][1]==mp[r][1]){
			if(mp[l][2] != mp[r][2]){
				ans+=mp[r][1];
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
