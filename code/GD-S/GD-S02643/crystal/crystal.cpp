#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],l,r,ans,m,mid,s[500005],f;
bool check(long long x){
	for(int i=x;i<=n;i++){
		f=a[i]*x-(s[i]-s[i-x]);
		if(f<=m)
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	l=1,r=n;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	while(l<=r){
		mid=(l+r+1)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
