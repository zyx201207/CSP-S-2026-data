#include<bits/stdc++.h>
using namespace std;
long long cnt[210000];
char c[210000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt[i]>>c[i];
	}
	int r=n,l=1;long long ans=0;
	while(l<r){
		if(c[l]==c[r]){
			long long j=min(cnt[l],cnt[r]);
			cnt[l]-=j,cnt[r]-=j;
			if(cnt[l]==0)l++;
			if(cnt[r]==0)r--;
		}else{
			long long j=min(cnt[l],cnt[r]);
			ans+=j,cnt[l]-=j,cnt[r]-=j;
			if(cnt[l]==0)l++;
			if(cnt[r]==0)r--;
		}
	}
	cout<<ans;
	return 0;
} 
