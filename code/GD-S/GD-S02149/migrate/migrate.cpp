#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long a[2000006],d;
bool judge(int l,int r) {
	long long cnt=0;
	for(int i=l;i<=r;i++) {
		if(a[i]-a[l]<=d&&a[r]-a[i]<=d) cnt++;
	}
	return cnt==2;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		long long cnt=0;
		for(int i=1;i<=n-3;i++) {
			for(int j=i+3;j<=n;j++) {
				if(judge(i,j)) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
