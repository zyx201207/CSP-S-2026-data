#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1;
	for(long long r=2;r<=n;r++){
		while(m<(a[r]-a[r-1])*(r-l)){
			m+=a[r-1]-a[l];
			l++;
		}
		m-=(a[r]-a[r-1])*(r-l);
		maxn=max(maxn,r-l+1);
	}
	cout<<maxn;
	return 0;
}
