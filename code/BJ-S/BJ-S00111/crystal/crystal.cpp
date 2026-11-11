#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],mx,ans;
long long cc(long long x){
	long long sum=0,cnt=0;
	for(int i=1;a[i]<=x;i++){
		sum+=x-a[i];
		cnt++;
	}
	if(sum>m)return 0;
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	long long l=1,r=mx+1;
	while(l<=r){
		long long mid=(l+r)/2;
		long long tt=cc(mid);
		if(tt==0){
			r=mid-1;
		}
		else l=mid+1,ans=tt;
		
	}
	cout<<ans<<endl;
	return 0;
}
