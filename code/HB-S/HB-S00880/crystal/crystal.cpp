#include<bits/stdc++.h>
using namespace std;
long long n,a[500001],sum,m,ans,maxn;
int main(){
	freopen("crystal,in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans=0; sum=0;
		for(int j=i;j>=1;j--){
			sum+=a[i]-a[j];
			ans++;
			if(sum>m) break;
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
