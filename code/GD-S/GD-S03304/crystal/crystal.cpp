#include<bits/stdc++.h>
using namespace std;
typedef long long llong;
const int maxn=5e5+50;
int n;
llong m,a[maxn],sum,S;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>1;--i){
		a[i]-=a[i-1];
	}
	a[1]=0;
	int j=1,ans=1;
	for(int i=2;i<=n;++i){
		sum+=a[i];
		S+=a[i]*(i-j);
		for(;j<i;++j){
			if(S<=m){
				break;
			}
			S-=sum;
			sum-=a[j+1];
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
	return 0;
}
