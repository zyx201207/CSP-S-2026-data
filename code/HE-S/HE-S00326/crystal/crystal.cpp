#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5;
long long n,m,a[N],b[N],sum[N],maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			b[i]+=a[i]-a[j];
			sum[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]<=m)maxn=sum[i];
	}
	cout<<maxn;
	return 0;
} 
