#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
unordered_map<int,int>mp;
int n,k,a[N],ans[N],b[N],f;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1; i<=n; i++) {
		if(b[i]!=a[i]) f=1;
	}
	if(!f) {
		for(int i=1; i<=k; i++) {
			int pos=upper_bound(a+1,a+n+1,i)-a;
			cout<<pos-1<<' ';
		}
		return 0;
	}
	for(int j=1; j<=n; j++) {
		int st=j;
		for(int i=j; i<=n; i++)
			mp[a[i]]++;
		while(st<=n) {
			int old=st;
			if(mp[a[st]]==1) {
				ans[a[st]]++;
				st++;
				continue;
			}
			for(int i=n; i>st; i--) {
				if(a[i]==a[st]) {
					st=i;
					break;
				}
			}
			for(int i=old; i<st; i++) mp[a[i]]--;
		}
		mp.clear();
	}
	for(int i=1; i<=k; i++) {
		cout<<ans[i]<<' ';
	}
}
