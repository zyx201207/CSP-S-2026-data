#include<bits/stdc++.h>
#include<cstdio>
#define int long long
using namespace std;
int n,m,a[500010],s[500010],sum[500010],cnt[500010],p=0,ans=0,j=0,z=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		s[i]=a[i]-a[i-1],sum[i]=s[i]+sum[i-1],cnt[i]=cnt[i-1]+(i-1)*s[i];
		if(s[i]!=s[i-1]) p=1;
	}
	for(int i=2;i<=n;i++){
		if(cnt[i]<=m){
			ans=i,z=cnt[i];
			continue;
		}
		z+=(i-1)*s[i];
		if(z<=m) ans=i-j;
		else{
			while(z>m){
				j++;
				z-=(sum[i]-sum[j]);
			}
			ans=max(ans,i-j); 
		}
	}
	cout<<ans<<endl; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
