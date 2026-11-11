#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1,a[500010];
bool check(){
	for(int i = 2;i < n;i ++){
		if(a[i-1]-a[i]!=a[i]-a[i+1]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i ++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int l = 1;l <= n;l ++){
			for(int r = l+1;r <= n;r ++){
				long long t=m,cnt=1; 
				for(int i = l;i < r;i ++){
					if((a[i+1]-a[i])*cnt>t) break;
					else {
						t-=(a[i+1]-a[i])*(cnt);
						cnt++;
					}
				}
				ans=max(ans,cnt);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(check()){
		long long cnt=1,t=m;
		for(int i = 1;i < n;i ++){
			if((a[i+1]-a[i])*cnt>t) break;
			else {
				t-=(a[i+1]-a[i])*(cnt);
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
}
