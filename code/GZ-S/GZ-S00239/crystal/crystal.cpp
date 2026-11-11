//GZ-S00239 遵义汇川区周林学校 陈俊洁
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
//long long cf[500005];
int tmp;
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal10.ans","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
//		cf[i]=a[i]-a[i-1];
	}
	sort(a+1,a+1+n);
	long long ans=0;
	bool fl=0;
	for(long long i=2;i<=n;i++){
		long long sum=0;
		long long cnt=0;
		for(long long j=1;j<=i;j++){
			sum+=a[i]-a[j];
			fl=1;
//			cout<<sum<<"+++\n";
			if(sum>m){
				sum=0;
				continue;
			}
			
			cnt++;
		}
		ans=max(ans,cnt);
	}
	if(fl==1) cout<<ans;
	else cout<<1;
	return 0;
}

