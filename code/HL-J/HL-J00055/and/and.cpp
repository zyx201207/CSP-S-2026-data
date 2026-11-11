#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],sum[40],ans;
bool can[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],can[i]=1;
	for(int k=30;k>=0;k--){
		int sum=0;
		for(int i=1;i<=n;i++)
			if((a[i]&(1<<k))&&can[i])sum++;
		if(sum<m)continue;
		ans+=(1<<k);
		for(int i=1;i<=n;i++)
			if(!(a[i]&(1<<k)))can[i]=0;
	}
	cout<<ans;
	return 0;
}