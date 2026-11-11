#include<bits/stdc++.h>
using namespace std;
const long long N=1e6;
long long n,m;
long long a[N];
bool s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long x=a[2]-a[1];
	for(long long i=3;i<=n;i++){
		if(a[i]-a[i-1]!=x)s=1;
	}
	if(!s){//具有特殊性质A、B 
		long long ans=0;
		long long cnt=1;
		for(long long i=n-1;i>=1;i--){
			if(ans+a[n]-a[i]<=m){
				ans+=a[n]-a[i];
				cnt++;
			}
			else{
				cout<<cnt;
				return 0;
			}
		}
		cout<<cnt;
		return 0;
	}
	long long ans=1;
	for(long long i=n;i>=2;i--){
		long long cnt=1,all=0;
		for(long long j=i-1;j>=1;j--){
			if(all+a[i]-a[j]<=m){
				all+=a[i]-a[j];
				cnt++;
			}else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
