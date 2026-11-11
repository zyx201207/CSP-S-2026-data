#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum=0,c[500005],ans=0;
int main(){
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) c[i]=abs(a[i+1]-a[i]);
	for(int i=1;i<=n;i++){
		for(long long k=1,j=i;;k++,j++){
			if((sum+k*c[j])>m||k>n||j>=n) break;
			sum+=k*c[j];
			ans=max(ans,k+1);
		}
		sum=0;
	}
	cout<<ans;
}
