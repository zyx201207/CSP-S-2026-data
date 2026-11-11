#include <bits/stdc++.h>
using namespace std;
int cnt[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt[i]>>c[i];
	}
	int l=1,r=n;
	long long ans=0;
	while(l<=r){
	      if(c[l]!=c[r]){
	      	if(cnt[l]<cnt[r]){
	      		ans+=cnt[l];
	      		cnt[r]-=cnt[l];
	      		l++;
			  }
			if(cnt[l]>cnt[r]){
				ans+=cnt[r];
				cnt[l]-=cnt[r];
				r--;
			}
			if(cnt[l]==cnt[r]){
				ans+=cnt[l];
				cnt[l]=0;cnt[r]=0;
				l++;r--;
			}
		  }
		else{
			if(cnt[l]<cnt[r]){
				l++;
				cnt[r]-=cnt[l];
			}
			if(cnt[l]>cnt[r]){
				r--;
				cnt[r]-=cnt[l];
			}
			if(cnt[l]==cnt[r]){
				cnt[l]=0;cnt[r]=0;
				l++;r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
