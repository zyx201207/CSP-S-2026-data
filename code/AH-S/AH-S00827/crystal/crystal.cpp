#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,ans=1;
int a[N],b[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	int flag=0;
	for(int i=1; i<=n; i++) {
		if(a[i]!=i) flag=1;
	}
	if(flag==0) {
		for(int i=1; i<=n-1; i++) {
			if(m-i>=0) {
				m-=i;
				ans++;
			}
			else break;
		}
		cout<<ans<<endl;
		return 0;
	}
	flag=0;
	sort(a+1,a+1+n);
	for(int i=3; i<=n; i++) {
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) {
			flag=1;
			break;
		}
	}
	if(flag==0) {
		int cha=a[2]-a[1];
		for(int i=1; i<=n-1; i++) {
			if(m-cha*i>=0) {
				ans++;
				m-=cha*i;
				continue;
			}
			else break;
		}
		cout<<ans<<endl;
		return 0;
	}
	int sum=1,cnt=0;
	for(int i=n; i>=1; i--) {
		sum=1,cnt=0;
		if(i<=ans) break;
		for(int j=1; j<i; j++) {
			b[++cnt]=a[i]-a[j];
		}
		sort(b+1,b+1+cnt);
		int t=m;
		for(int k=1; k<=cnt; k++) {
			if(t-b[k]>=0) {
				t-=b[k];
				sum++;
				continue;
			}
			else break;
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
