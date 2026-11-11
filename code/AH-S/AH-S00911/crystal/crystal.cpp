#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long sum,cnt=1;
long long ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum=sum+(a[i]-a[i-1])*cnt;
		cnt++;
		while(sum>m){
			sum=sum-(a[i]-a[i-cnt]);
			cnt--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
