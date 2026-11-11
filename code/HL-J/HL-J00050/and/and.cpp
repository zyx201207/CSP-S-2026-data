#include <bits/stdc++.h>
using namespace std;
long long n,m,maxn,num,zt[200005];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>zt[i];
	sort(zt+1,zt+n+1,cmp);
	for(int i=1;i<=n-m+1;i++){
		num=zt[i];
		for(int j=i+1;j<m;j++){
			num&=zt[j];
		}
		maxn=max(maxn,num);
	}
	cout<<maxn;
	return 0;
}
