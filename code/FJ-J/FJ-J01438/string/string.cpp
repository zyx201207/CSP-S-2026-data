#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int> cnt(n+1);
	vector<char> charr(n+1);
	for(int i=1;i<=n;i++)cin>>cnt[i]>>charr[i];
	int l=1,r=n;
	int ans=0;
	while(l<r){
		if(charr[l]==charr[r]){
			if(cnt[l]>cnt[r])cnt[l]-=cnt[r],r--;
			else if(cnt[r]>cnt[l])cnt[r]-=cnt[l],l++;
			else r--,l++;
		}
		else {
			if(cnt[l]>cnt[r])ans+=cnt[r],cnt[l]-=cnt[r],r--;
			else if(cnt[r]>cnt[l])ans+=cnt[l],cnt[r]-=cnt[l],l++;
			else ans+=cnt[r],r--,l++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

