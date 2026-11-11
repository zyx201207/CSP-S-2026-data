#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N=2e5+7;
int n,m,a[N],sum;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1) {
		cout<<a[1];
		return 0;
	}
	for(int i=0;i<(1<<n);i++) {
		int cnt=0,ans=1;
		for(int j=0;j<=n;j++) {
			if(i&(1<<j)){
				cnt++;
				ans&=a[j];
			}
			if(cnt==m) {
				sum=max(sum,ans);
			}
		}
	}
	cout<<sum;
	return 0;
}