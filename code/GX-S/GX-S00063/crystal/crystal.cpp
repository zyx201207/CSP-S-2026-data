#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=1,now=0,cnt=0,p=0;cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];if(a[i]==i)cnt++;
		if(i>=2 and a[i]-a[i-1]==a[i-1]-a[i-2])p++;
	}
	sort(a+1,a+n+1);
	if(a[1]<0){
		for(int i=1;i<=n;++i){
			a[i]-=a[1];
		}
	}
	for(int i=1;i<=n;++i){
		d[i]=d[i-1]+a[i];
	}
	if(cnt==n){
		long long l=0,r=1e9,ans2=0;
		while(r-l>=0){
			long long mid=(l+r)>>1;
			if(mid*(mid+1)/2<=m){
				l=mid+1;ans2=mid;
			}
			else{
				r=mid-1;
			}
		}
		cout<<min(ans2+1,n)<<"\n";
		return 0;
	}
	if(p==n-1){
		long long sum=a[2]-a[1];
		long long l=0,r=1e9,ans2=0;
		while(r-l>=0){
			long long mid=(l+r)>>1;
			if(sum/2*(mid+1)*mid<=m){
				l=mid+1;ans2=mid;
			}
			else{
				r=mid-1;
			}
		}
		cout<<min(ans2+1,n)<<"\n";
		return 0;
	}
	if(n<=5000){
		long long ans2=1,now2=1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=i;++j){
				if(a[i]*(i-j)-(d[i]-d[j-1])<=m){
					if(ans2<(i-j)){
						ans2=max(ans2,(long long)(i-j));now2=a[i];
					}
					break;
				}
			}
		}
		cout<<ans2<<"\n";return 0;
	}
	for(long long i=2;i<=n;++i){
		if(a[i]==a[now]){
			ans++;continue;
		}
		long long sum=d[i]+m;
		if(min(sum/a[i],i)>=ans){
			ans=max(ans,min(sum/a[i],i));
			now=a[i];
		}
	}
	cout<<ans<<"\n";
	return 0;
}
