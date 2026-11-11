#include<bits/stdc++.h>
using namespace std;
int a[2*100010],maxn=INT_MIN,m,n;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n-m;i++){
		int cnt=a[i];
		for(long long j=i+1;j<=i+m;j++){
			cnt=(cnt&a[j]);
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
}
