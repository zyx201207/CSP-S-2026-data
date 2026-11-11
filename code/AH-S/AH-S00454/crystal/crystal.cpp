#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N],d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) d[i]=d[i-1]+a[i];
	long long l=1,r=1,maxn=0;
	while(r<=n){
		while(a[r]*(r-l+1)-(d[r]-d[l-1])>m&&l<r) l++;
		maxn=max(maxn,r-l+1);
		r++;
	}
	cout<<maxn;
	return 0;
}
