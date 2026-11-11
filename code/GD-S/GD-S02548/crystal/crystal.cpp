#include <bits/stdc++.h>
using namespace std;
const int maxn=500014;
long long n,k,a[maxn],s[maxn]={0},ans=-1,x=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	if(n>=6000){
		for(long long i=1;i<=n;i++){
			long long p=a[i]*i-s[i];
			if(p<k){
				x=i;
			}
			else if(p>=k){
				while(a[i]==a[i+1]&&i<n){
					i++;
				}
				cout<<i;
				return 0;
			}
		}
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long p=a[j]*(j-i+1)-s[j]+s[i-1];
			if(p<=k){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
