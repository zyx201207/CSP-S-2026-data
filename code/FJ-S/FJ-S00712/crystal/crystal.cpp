#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],sum=0,l=1,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n),ans=1,sum=a[1];
	for(long long i=2;i<=n;++i){
		sum+=a[i];
		while(l<i){
			if(a[i]*(i-l+1)-sum>m)sum-=a[l],++l;
			else break;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
