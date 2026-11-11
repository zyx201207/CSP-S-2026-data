#include <bits/stdc++.h>
using namespace std; 
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,sum=1,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		sum=1;
		long long kb=m;
		for(int j=i-1;j>=1;j--){
			if(kb>=a[i]-a[j]) kb-=(a[i]-a[j]),sum++;
			else break;
		}
		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
}
