#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'
int n,m,a[500005],sdf[500005],df[500005],ans;
int len,sy,head=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		df[i-1]=a[i]-a[i-1];
		sdf[i]=sdf[i-1]+df[i];
	}
	for(int i=1;i<n;i++){
		len++;
		while(sy>m-len*df[i]){
			sy=sy-sdf[i+1]+sdf[head];
			head++;
			len--;
		}
		if(sy<=m-len*df[i]){
			sy+=len*df[i];
		}
		ans=max(ans,len);
	}
	cout<<ans+1<<endl;
	return 0;
}
