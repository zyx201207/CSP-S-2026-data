#include<bits/stdc++.h>
using namespace std;
long long n,m,mm,a[510001],cnt,ans=-1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>mm;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		m=mm;
		cnt=0;
		bool flag=false;
		for(long long j=i-1;j>=1;j--){
			if(m- (a[i]-a[j]) < 0) break;
			else{
				flag=true;
				m -= (a[i]-a[j]);
				cnt++;
				if(m==0) break;
			}
		}
		if(flag) cnt++;
		ans = max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
