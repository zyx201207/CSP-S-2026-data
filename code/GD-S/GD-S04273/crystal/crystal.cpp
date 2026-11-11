#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500005];
long long b[500005];
vector<long long>c;
bool cmp(long long a1,long long a2){
	return a1<a2;
}
int  main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[0]=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		c.push_back(a[i]*(i-1)-b[i-1]);
	}
	long long ans=lower_bound(c.begin(),c.end(),m)-c.begin();
	ans+=1;
	while(a[ans]==a[ans+1]&&ans<n){
		ans++;
	}
	if(ans>n)ans=n;
	cout<<ans;
	return 0;
}
