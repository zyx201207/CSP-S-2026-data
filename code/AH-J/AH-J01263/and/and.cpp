#include <bits/stdc++.h>
using namespace std;
int n,m;
long long maxl=-1,sum,a[200005];
bool cmp(long long x,long long y){
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxl=max(maxl,a[i]);
	}
	if(m==1) {
		cout<<maxl;
		return 0;
	}
	maxl=-1;
	sort(a+1,a+1+n,cmp);
	if(m==n){
		cout<<a[n];
		return 0;
	}
	if(m==2){
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			maxl=a[i];
			break;
		}
	}
}
	sum=a[m];
	if(sum<maxl) cout<<maxl;
	else cout<<sum;
	return 0;
} 
