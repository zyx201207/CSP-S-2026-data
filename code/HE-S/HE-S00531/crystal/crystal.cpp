#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
int ans;
long long a[N],summ[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)summ[i]=summ[i-1]+a[i];
	for(int i=1,l=1;i<=n;i++){
		while(summ[i]-summ[l-1]-a[i]*(i-l+1)+m<0) l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
