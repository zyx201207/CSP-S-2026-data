#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[2000005];
long long num[2000005];

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) {
		cin>>n>>m;
		memset(a,0,sizeof(a));
		for(int i=1; i<=n; i++) {
			num[i]=i;
		}
		cin>>a[1]>>a[2];
		bool check=0;
		int minn=INT_MAX;
		for(int i=3; i<=n; i++) {
			scanf("%d",&a[i]);
			minn=min(minn,a[i]);
		}
		//sort(a+1,a+n+1);
		for(int i=3; i<=n; i++) {
			if(a[i]-a[i-1]!=a[2]-a[1]) check=1;
		}
		int cha=abs(a[2]-a[1]);
		long long longn=ceil(m/cha);
		if(check==0&&longn>2) {
			cout<<0<<'\n';
//
//			if(longn<=1) cout<<0;
//			else {
//				cout<<max(n-longn-2+1,0);
//			}
//			continue;
//		} else if((n-longn-2+1)<0) {
//			cout<<0<<'\n';
		} else if(check==0&&longn==2) {
			cout<<max(n-longn-2+1,(long long)0)<<'\n';
		} else {
			minn=-minn;
			for(int i=n; i>=1; i--) {
				a[i+minn]=a[i];
			}
			long long ans=0;
			for(int i=1; i<n; i++) {
				for(int j=1; j<=m; j++) {
					num[a[i]+j+minn]=min(num[a[i]+j+minn],num[a[i]+minn]+1);
				}
			}
			for(int i=1; i<=n; i++) {
				//cout<<num[i+minn]<<" ";
				if(num[i+minn]==3) ans++;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}