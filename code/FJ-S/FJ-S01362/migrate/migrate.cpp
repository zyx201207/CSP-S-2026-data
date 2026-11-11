#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
long long b[2000005],c[2000005];
int flag[2000005];
long long n,d,tot=1;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c2,t;
	cin>>c2>>t;
	for(int qqq=1; qqq<=t; qqq++) {
		cin>>n>>d;
		tot=1;
		for(int i=1; i<=n; i++) {
			b[i]=INT_MAX;
			c[i]=INT_MAX;
			cin>>a[i];
		}
		b[n+1]=INT_MAX;
		c[n+1]=INT_MAX;
		for(int i=1; i<=n; i++) {
			//cout<<lower_bound(a+1,a+1+n,a[i]-d)-a<<endl;
			int x=lower_bound(a+1,a+1+n,a[i]+d)-a;
			while(a[x]>a[i]+d) {
				x--;
			}
			int y=0;
			if(x-1!=i) {
				x--;
				y=lower_bound(a+1,a+1+n,a[x]+d)-a;
				while(a[y]>a[x]+d) {
					y--;
				}
			}
			if(y!=0 && y<=n && y!=x+1 && y!=x) {
				b[tot]=i;
				c[tot]=y;
				//flag[i]=1;
				flag[y]=1;
				//cout<<b[tot]<<" "<<c[tot]<<endl;
				tot++;
			}
		}
		long long ans=0;
		long long ans1=0;
		long long ans2=0;
		for(int i=1; i<tot; i++) {
			long long j=b[i];
			while(a[j]-a[j-1]<=d && j-1>=1 &&j>c[i-1]) {
				j--;
			}
			ans1=b[i]-j+1;
			long long j2=c[i];
			while(a[j2+1]-a[j2]<=d&&j2+1<=n&&j2<b[i+1]) {
				j2++;
			}
			ans2=j2-c[i]+1;
			ans=ans+ans1*ans2;
			b[i]=INT_MAX;
			c[i]=INT_MAX;
		}
		for(int i=1; i<=n; i++) {
			a[i]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}