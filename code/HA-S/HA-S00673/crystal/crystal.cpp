#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],cnt;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(a[n]-a[n-1]==1) {
		ll maxx=a[n];
		while(m!=0) {
			cnt++;
			for(int i=1; i<=cnt; i++) {
				if(a[1]>=maxx) {
					break;
				}
				if(m>0) {
					a[i]++;
					m--;
				} else {
					break;
				}
				if(a[1]>=maxx) {
					break;
				}
			}
		}
		if(a[1]<=maxx) {
			cout<<a[1];
		} else {
			cout<<maxx;
		}
	} else {
		ll cha=a[n]-a[n-1];
		while(m!=0) {
			cnt++;
			for(int i=1; i<=cnt; i++) {
				if(m>=cha) {
					a[i]+=cha;
					m-=cha;
				} else {
					break;
				}
			}
		}
		cout<<a[1]/cha;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
