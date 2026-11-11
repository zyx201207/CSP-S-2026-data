#include<bits/stdc++.h>
using namespace std;
long long n,cnt[200001],ans;
char t[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;long long l=1,r=n;
	for(int i=1;i<=n;i++)cin>>cnt[i]>>t[i];
	while(l<r){
		if(t[l]==t[r]){
			if(cnt[l]==cnt[r])l++,r--;
			else if(cnt[l]>cnt[r])cnt[l]-=cnt[r],r--;
			else cnt[r]-=cnt[l],l++;
		}else if(t[l]!=t[r]){
			if(cnt[l]==cnt[r])ans+=cnt[l],l++,r--;
			else if(cnt[l]>cnt[r])cnt[l]-=cnt[r],ans+=cnt[r],r--;
			else cnt[r]-=cnt[l],ans+=cnt[l],l++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
