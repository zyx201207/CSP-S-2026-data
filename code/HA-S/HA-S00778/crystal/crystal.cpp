#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N];
long long ans[N];
long long d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool flag1=0;
	long long cnt1=a[2]-a[1];
	for(int i=1;i<n;i++){
		cnt+=a[n]-a[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=cnt1){
			flag1=1;
			break;
		}
	}
	if(cnt<=m){
		cout<<n;
		return 0;
	}
	if(!flag1){
		long long b=m/cnt1;
		long long c=1;
		while(b-c>=0){
			b-=c;
			c++;
		}
		cout<<c;
		return 0;
	}
	for(int i=n;i>=1;i--){
		long long sum=0;
		long long cnt=1;
		for(int j=i-1;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum>m){
				ans[i]=cnt;
				break;
			}
			if(sum==m){
				ans[i]=cnt+1;
				break;
			}
			cnt++;
		}
	}
	long long ma=-1;
	for(int i=1;i<=n;i++){
		ma=max(ma,ans[i]);
	}
	cout<<ma;
	return 0;
}