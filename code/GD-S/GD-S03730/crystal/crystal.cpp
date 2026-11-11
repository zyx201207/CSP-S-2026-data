#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500100];
int cnt,ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cnt=n;
	
	if(m==0){
		int cc=1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				cc++;
			}else{
				cc=1;
			}
			ans=max(ans,cc);
		}
	}
	else{
		for(int i=n;i>=1;i--){
			if(cnt>i) cnt=i;
			while(m>=(a[i]-a[cnt-1]) && cnt>1){
				cnt--;
				m-=(a[i]-a[cnt]);
			}
			ans=max(ans,i-cnt+1);
			if(i!=1&&i!=cnt){
				m+=(i-cnt+1)*(a[i]-a[i-1]);
			}
		}	 
	}
	
	cout<<ans;
	return 0;
}
