#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
long long a[N],sum[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	bool ba=1,bb=1;
	long long m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i)ba=0;
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&n>=3)bb=0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	if(n==1){
		cout << 1;
	}else if(n==2){
		if(a[2]-a[1]<=m){
			cout << 2;
		}else{
			cout << 1;
		}
	}else if(ba){
		int now=1,ans=1;
		while(m>=now&&now<n){
			m-=now;
			now++;
			ans++;
		}
		cout << ans << endl;
	}else if(bb){
		int now=a[n]-a[n-1],ans=1;
		while(m>=now&&now/(a[n]-a[n-1])<n){
			m-=now;
			ans++;
			now+=a[n]-a[n-1];
		}
		cout << ans << endl;
	}else{
		long long ans=1;
		for(int i=2;i<=n;i++){
//			long long cnt=1,_m=m;
//			for(int j=i-1;j>=1;j--){
//				if(_m<a[i]-a[j]){
//					break;
//				}
//				_m-=a[i]-a[j];
//				cnt++;
//			}
//			ans=max(ans,cnt);
			int l=1,r=i-1;
			while(l<=r){
				long long mid=(l+r)>>1;
				if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m){
					ans=max(ans,i-mid+1);
					r=mid-1;
				}else{
					l=mid+1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
