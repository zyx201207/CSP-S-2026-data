#include <bits/stdc++.h>
using namespace std;
long long n,m,maxans=1;
long long arr[500010];
bool flagA=true,flagB=true;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++) if(arr[i]!=i) flagA = false;
	long long cha = arr[2]-arr[1];
	for(int i=3;i<=n;i++) if(arr[i]-arr[i-1]!=cha) flagB = false;
	if(flagA){
		long long cnt = 1;
		while(m-cnt>=0){
			m -= cnt;
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	if(flagB){
		long long cnt = 1;
		while(m-cnt*cha>=0){
			m -= cnt*cha;
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long cnt=0,ans=1;
		for(int j=i-1;j>=1;j--){
			if(cnt+arr[i]-arr[j]<=m) ans++,cnt+=arr[i]-arr[j];
		}
		maxans = max(ans,maxans);
	}
	cout<<maxans;
	return 0;
}
