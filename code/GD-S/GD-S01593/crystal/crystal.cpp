#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500007;
int n,l,ans;
ll m,a[N],w;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	l=1;
	ans=1;
	for(int r=2;r<=n;r++){
		w+=(a[r]-a[r-1])*(r-l);
		while(w>m){
			w-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
