#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000000],sum,ans[100000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		sum=0;
		for(int j=i-1;j>=1;j--){
			sum=a[i]-a[j]+sum;
			if(sum<=m){
				ans[i]+=1;
			}
		}
	}
	sort(ans+1,ans+n+1);
	cout<<ans[n]+1;
	return 0;
}
