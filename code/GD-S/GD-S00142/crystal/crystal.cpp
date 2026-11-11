#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],s[500005];
long long maxn=0,sum=0,ans=0,w=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		s[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++){
		if(s[i]!=0){
			sum+=s[i]*i;
		}
		if(sum<=m){
			ans++;
			maxn=max(maxn,ans+1);
		}
		else{
			maxn=max(maxn,ans+1);
			ans+=1;
			while(sum>m){
				sum-=a[i]-a[w];
				ans--;
				w++;
			}
		}
	}
	cout<<maxn;
	return 0;
}
