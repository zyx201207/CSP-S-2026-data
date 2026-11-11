#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
long long m,a[N+5],cnt=0,ans=-1;
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long l=1,r=1;r<=n;r++){
		cnt+=(a[r]-a[r-1])*(r-l);
		while(cnt>m){
			cnt-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
