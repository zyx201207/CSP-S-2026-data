#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,cnt,f[500010],l=1;
unordered_map<long long,long long>k;
long long llmax(long long x,long long y){
	return x>y?x:y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		k[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+(a[i]-a[i-1])*(i-1);
		if(f[i]<=m) ans=i;
		else{
			int tar=m-f[i-1],t1=f[i]-f[i-1];
			//printf("%lld %lld %lld\n",m,t1,tar);
			while(tar<t1){
				tar+=a[i]-a[l];
				l++;
				//ans=llmax(ans,1ll*(tar/(a[i]-a[i-1]))+i-l-1);
			}
			ans=llmax(ans,k[a[i]]+ans-l+1);
			//ans=max(ans,ans+k[a[i]]-l+1);
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}
