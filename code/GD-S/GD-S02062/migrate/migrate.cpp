#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[100005];
long long bj[100005];
long long ans;
void find(long long u,long long v,long long a[100005],long long n,long long d) {
	bj[u]=1;
	if (u==v) {
		ans++;return;
	}
	if (a[u]+d>=a[v]) {
		ans++;return;
	} 
	for (int i=u+1;i<=v;i++) {
		if (a[i]+d>=a[v]) {
			ans++;return;
		}
		if(a[i]-a[u]<=d) {
			find(i,v,a,n,d);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--) {
		long long n,d;
		cin>>n>>d;	
		for (long long i=0;i<n;i++){
			cin>>a[i];
		}
		
		long long sum=0;
		for (long long i=0;i<n;i++) {
			for (long long j=i;j<n;j++) {
				ans=0;
				find(i,j,a,n,d);
				if(ans==2) sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
