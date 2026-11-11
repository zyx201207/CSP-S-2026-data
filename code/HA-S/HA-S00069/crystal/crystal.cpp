#include<bits/stdc++.h>
using namespace std;
long long a[1000000],df[1000000];
long long ans=1,cnt=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		df[i]=a[i]-a[i-1];
	}
	sort(df+1,df+n+1);
	while(cnt<=m){
		cnt+=df[ans];
		ans++;
	}
	cout<<ans+1;
	return 0;
}
