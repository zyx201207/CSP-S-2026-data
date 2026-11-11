#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,p,b[500005];
long long gm(int h,int t){
	long long ret=0;
	for(int i=h;i<=t;i++){
		ret+=a[t]-a[i];
	}
	return ret;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1)p+=(a[i]-a[i-1])==1;
	}
	sort(a+1,a+1+n);
	if(p==n-1){
//		cout<<1<<endl;
		for(ans=2;ans<=n&&ans*(ans+1)/2<=m;ans++);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			long long x=gm(i,j);
			if(x>m)break;
			if(j-i+1>ans){
				ans=j-i+1;
//				cout<<i<<" "<<j<<" "<<x<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}
