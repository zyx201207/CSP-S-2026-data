#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],sum[1000000],maxn=0;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]&a[i];
	} 
	for(int i=m;i<=n;i+=m){
		maxn=max(maxn,sum[i]);
	}
	cout<<maxn;
		return 0;
} 
