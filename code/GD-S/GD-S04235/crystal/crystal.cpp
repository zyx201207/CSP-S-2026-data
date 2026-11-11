#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3fll
#define int ll
#define endl '\n'
#define lowbit (x&(-x))
typedef long long ll;
using namespace std;
const int N=1000010;

int n,m;
int a[N],sum[N],ans=-inf;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum[1]=a[1];
	for(int i=2;i<=n;i++)sum[i]=sum[i-1]+a[i];
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	//cout<<endl;
	
	
	for(int i=n,j=n;i>=1;i--){
		while(j>=2&&((a[i]*(i-j+2))-(sum[i]-sum[j-2]))<=m)j--;
		ans=max(ans,i-j+1);
		//cout<<i<<" "<<j<<" "<<sum[i]-sum[j-1]<<" "<<((a[i]*(i-j+1))-(sum[i]-sum[j-1])<=m)<<endl;
	}
	
	cout<<ans<<endl;
	return 0;
}

