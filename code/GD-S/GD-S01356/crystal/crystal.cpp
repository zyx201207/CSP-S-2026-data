#include<iostream>
#include<algorithm>
#include<cstring>
#include<deque>
using namespace std;
int n;
long long m;
long long a[500005];
long long pre=0;
long long cnt=0;
int ans=1;
long long dp[5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(m==0){
		cout<<1;
		return 0;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
		int l=1;
		int len=1;
		for(int i=2;i<=n;++i){
			long long pq=(a[i]-a[i-1])*(i-1);
			cnt+=pq;
			++len;
			while(l<=i && cnt>m){
				cnt-=(a[i]-a[l]);
				++l;
				--len;
			}
			ans=max(ans,len-1);
		}
		cout<<ans;
	
	return 0;
} 
