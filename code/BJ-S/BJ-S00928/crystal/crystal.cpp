#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],sum,cha,ans,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		k=m;
		sum=0;
		for(long long j=i-1;j>=1;j--){
			cha=a[i]-a[j];
			if(k-cha>=0){
				k-=cha;
				sum++;
			}else{
				continue;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans+1;
	return 0;
}
