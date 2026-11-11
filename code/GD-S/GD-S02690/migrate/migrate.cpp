#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) {
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		int l=1,r=n,ans=0;
		while(l<r) {
			if(a[r]-a[l]>d) {l++;continue;}
			if(r-l-1==1 && a[r-1]-a[l-1]<=d) {ans++;l=1;r--;}
			else break;
		}
		cout<<ans-1<<"\n";
	}
	return 0;
}
