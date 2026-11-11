#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],pre[N];
long long maxn=-1000005;
long long tot=0;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int l=1;l<=n-m+1;l++){
		int r=l+m-1;
		tot=a[l];
		for(int i=l+1;i<=r;i++){
			tot&=a[i];
		}
		maxn=max(maxn,tot);
	}
	cout<<maxn;
} 