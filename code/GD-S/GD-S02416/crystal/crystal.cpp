#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn;
long long a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=n;i>=1;i--){
		long long p=m,s=0;
		for(long long j=i-1;j>=1;j--){
			if(p>=a[i]-a[j]){
				p=p-(a[i]-a[j]);
				s++;
				maxn=max(s,maxn);
			}else{
				break;
			}
		}
	}
	cout<<maxn+1;
	return 0;
}
