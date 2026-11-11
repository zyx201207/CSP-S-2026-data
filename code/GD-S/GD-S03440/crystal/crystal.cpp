#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510000;

int n,m;
int a[N],s[N];
int ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int l=1,sum=0;
	for(int i=2;i<=n;i++){
		sum=(a[i]*(i-l)-(s[i-1]-s[l-1]));
		while(sum>m){
			sum-=(a[i]-a[l]);l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	
	return 0;
}
