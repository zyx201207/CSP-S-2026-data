//GZ-S00224 卓然 贵阳中天中学
#include<bits/stdc++.h>
using namespace std;
long long s[500005];
long long y[500005];
long long a[500005];
long long ans=1;
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		s[i]=a[i]-a[i-1];
		y[i]=a[i]-a[i-1];
	}
	for(long long len=3;len<=n;len++){
		for(long long i=1;i<=n-len+1;i++){
			s[i]=s[i]+y[i+len-1]*(len-1);
			if(s[i]<=m)ans=max(ans,len);
			else{
				cout<<ans;
				return 0;
			}
		}
	}
	cout<<ans;
	return 0;
}

