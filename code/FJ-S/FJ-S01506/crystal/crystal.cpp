#include<bits/stdc++.h> 
using namespace std;
long long a[500005],m,n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=1;
	long long sum=0;
	long long len=1;
	int l=1;
	for(int i=2;i<=n;i++){
		sum=sum+(a[i]-a[i-1])*len;
		++len;
		while(sum>m){
			sum=sum-a[i]+a[l++];
			len--;
		} 
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}

