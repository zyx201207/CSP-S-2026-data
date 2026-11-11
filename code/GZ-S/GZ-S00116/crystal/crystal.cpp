//贵阳第一中学 GZ-S00116 胡祺然
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],sum,j,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	j=n;
	sum=a[n];
	for(int i=n;i>=1;i--){
		sum-=a[i+1];
		while(j>1&&m+sum+a[j-1]>=(a[i]*(i-j+2))){
			j--;
			sum+=a[j];
			ans=max(ans,i-j+1);
		}
	}
	cout<<ans;
	return 0;
}
