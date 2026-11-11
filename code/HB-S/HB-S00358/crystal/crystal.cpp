#include<bits/stdc++.h>
using namespace std;
long long a[505050];
long long s[505050];
int n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=1;
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	for(int i=1;i<=n;i++){
		long long ma=0;
		long long l=1,r=i;
		while(l<r){
			long long mid=(l+r)/2;
			long long he=a[i]*mid;
			long long check=he-(s[i-1]-s[i-mid-1]);
			if(check<=m){
				ma=max(ma,mid);
				l=mid+1;
			}else{
				r=mid;
			}
		}
		ans=max(ans,ma+1);
	}
	
	cout<<ans;
	return 0;
}
