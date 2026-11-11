#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n;
	long long m;
	cin>>m;
	bool tr=true;
	cin>>a[1];
	cin>>a[2];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) tr=false;
	}
	sort(a,a+n+1);
	if(tr){
		long long t=m;
		long long ans=1;
		for(int j=n-1;j>=1;j--){
			long long x=a[n]-a[j];
			if(t-x<0) break;
			t-=x;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a,a+n+1);
	long long ma=INT_MIN;
	for(int i=n;i>1;i--){
		long long t=m;
		long long ans=1;
		if(ma>i) break;
		
		for(int j=i-1;j>=1;j--){
			long long x=a[i]-a[j];
			if(t-x<0) break;
			t-=x;
			ans++;
		}
		ma=max(ans,ma);
	}
	cout<<ma;
	return 0;
}
