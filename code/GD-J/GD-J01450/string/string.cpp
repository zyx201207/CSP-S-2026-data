#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+ 10;
int n ,ans;
int cnt[N];
char ax[N];
signed main(){ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt[i]>>ax[i];
	}
	int l = 1,r = n;
	while(r>l){
		if(ax[r] != ax[l]){
			if(cnt[l] >= cnt[r]){
				ans = ans + min(cnt[l],cnt[r]);
				cnt[l] -= cnt[r];
				cnt[r] = 0;
				r--;
			}else{
				ans = ans + min(cnt[r],cnt[l]);
				cnt[r] -= cnt[l];
				cnt[l] = 0;
				l++;
			}
		}else{
			if(cnt[l] >= cnt[r]){
				cnt[l] -= cnt[r];
				cnt[r] = 0;
				r--;
			}else{
				cnt[r] -= cnt[l];
				cnt[l] = 0;
				l++;
			}
		}
		if(cnt[l] == 0)l++;
		if(cnt[r] == 0)r--;
		//cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
