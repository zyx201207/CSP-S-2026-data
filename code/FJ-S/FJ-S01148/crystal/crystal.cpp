#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N],pre[N];
inline int check(int x)
{
	int l=1,r=x;
	int ans=x;
	while(l<=r){
		int mid=(l+r)>>1;
//		cout<<x<<" "<<mid<<" "<<pre[x]-pre[mid-1]+m<<" "<<a[x]*(x-mid+1)<<"\n";
		if(pre[x]-pre[mid-1]+m>=a[x]*(x-mid+1)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=max(ans,i-check(i)+1);
	}
	cout<<ans;
	return 0; 
}
