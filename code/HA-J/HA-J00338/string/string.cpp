#include<bits/stdc++.h>
using namespace std;
long long ans;
struct zk {
	long long gs;
	char nr;
} a[20005];
int main() {
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i].gs>>a[i].nr;
	}
	int l=0,r=n-1;
	while(r!=l) {
		if(r+1==l and a[r].gs==a[l].gs){
			break;
		}
		if(a[l].nr!=a[r].nr) {
			if(a[l].gs>a[r].gs) {
				ans+=a[r].gs;
				a[l].gs-=a[r].gs;
				r--;
			} else if(a[l].gs<a[r].gs) {
				ans+=a[l].gs;
				a[r].gs-=a[l].gs;
				l++;
			} else {
				ans+=a[r].gs;
				r--;
				l++;
			}
		}else{
			if(a[l].gs>a[r].gs){
				a[l].gs-=a[r].gs;
				r--;
			}else if(a[l].gs<a[r].gs){
				a[r].gs-=a[l].gs;
				l++;
			}else{
				r--;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
