#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5;
ll n,m,k,c,MAXN=0;
int a[N],bj[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n; i>=1; i--) {
		k=0;
		c=1;
		for(int j=i-1; j>=1; j--) {
			if(k==m) {
				break;
			}
			if(k<m) {
				k+=a[i]-a[j];
			}
			if(k<=m) {
				c++;
			} else {
				k=k-(a[i]-a[j]);
			}
		}
		bj[i]=c;
	}
	for(int i=1; i<=n; i++) {
		if(bj[i]>MAXN) {
			MAXN=bj[i];
		}
	}
	cout<<MAXN<<endl;
	return 0;
}
