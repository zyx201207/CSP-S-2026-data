#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-0x3f3f3f,a[500100],pre[500100];
int main() {
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid=(l+r+1)>>1;
		while(l<=r){
			mid=(l+r+1)>>1;
			if((i-mid+1)*a[i]-(pre[i]-pre[mid-1])>=m){
				l=mid+1;
			}
			else r=mid-1;
		}
		if(maxn<abs(i-mid+1)){
			maxn=abs(i-mid+1);
		}
	}
	cout<<maxn;
	return 0;
}//rp++!!
/*5 5
1 2 4 8 9 */
