#include<bits/stdc++.h>
using namespace std;
long long n,m,sj[500005],c[500005],ans=-10086;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1; i<=n; i++) {
		cin>>sj[i];
	}
	if(n<=5000) {
		sort(sj+1,sj+1+n);
		for (long long i=1; i<=n; i++) {
			for (long long j=i; j>=1; j--) {
				c[j]=sj[i]-sj[j];
			}
			long long k=m,j=i,cnt=0;
			while(k-c[j]>=0&&j>=1) {
				k-=c[j--];
				cnt++;
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	} else {
		int flag=1,zeta=2;
		for (long long i=1; i<=n; i++) {
			if (sj[i]!=i) flag=0;
		}
		for (long long i=1; i<=n-1; i++) {
			if (sj[i]-sj[i-1]!=sj[i+1]-sj[i]) zeta=0;
		}
		if (flag=1){
			int a=1,cnt=0;
			while (cnt+a<=m){
				cnt+=a++;
			}
			cout<<cnt;
			return 0;
		}
		else if(zeta=2){
			int a=1,cnt=0,t=sj[2]-sj[1];
			while (cnt+a<=m){
				cnt+=a;
				a+=t;
			}
			cout<<cnt;
			return 0;
		}
	}
	return 0;
}
