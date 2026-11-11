#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans=1;
signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m>1e5){
		m/=abs(a[1]-a[2]);
		int ikun=1;
		for(;m>0;ikun++){
			m-=ikun;
		}
		cout<<min(ikun-1,n);
		return 0;
	}
	sort(a+1,a+n+1);
	int mm=m,i=1,ikun=1;
	while(i+ikun<=n){
		if(ikun*(a[i+ikun]-a[i+ikun-1])>mm){
			while(mm<=ikun*(a[i+ikun]-a[i+ikun-1])){
				mm+=a[i+ikun]-a[i];
				i++;
				ikun--;
			}
		}
		mm-=ikun*(a[i+ikun]-a[i+ikun-1]);
		ikun++;
		ans=max(ans,ikun);
	}
	cout<<ans;
	return 0;
} 
