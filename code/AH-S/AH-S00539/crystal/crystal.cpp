#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,m;
int a[N],d[N],ma[N];
int mama(int i,int j){
	if(i==0||j==0)return 0;
	if(j==1)return d[i];
	if(j==2)return 2*ma[j-1]+d[i-j+1];
	return 2*ma[j-1]-ma[j-2]+d[i-j+1];
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i-1]=a[i]-a[i-1];
	}
	int maxn=0;
	for(int i=1;i<n;i++){
		for(int q=1;q<=N;q++){
			ma[i]=0;
		}
		for(int j=1;j<=i;j++){
			ma[j]=mama(i,j);
			if(ma[j]<=m){
				maxn=max(maxn,j+1);
			}
			else break;
		}
	}
	cout<<maxn;
	return 0;
}
