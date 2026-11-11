#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long m,a[500005],s[500005];
bool ck(int k){
	for(int i=k;i<=n;i++){
		if(a[i]*k-(s[i]-s[i-k])<=m)
			return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int l=1,r=n,ans;
	while(l<=r){
		int md=l+r>>1;
		if(ck(md)){
			ans=md;
			l=md+1;
		}
		else r=md-1;
	}
	cout<<ans;
	return 0;
}
