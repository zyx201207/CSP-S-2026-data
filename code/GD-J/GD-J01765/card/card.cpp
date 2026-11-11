#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans[500005],sum[500005],ju[500005];
vector<int> v;
int n,m,a[500005],l[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)l[i]=-1;
	for(int i=n;i>=1;i--){
		sum[i]++;
		if(l[a[i]]!=-1){
			ju[i]=l[a[i]];
		}
		l[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(sum[i]==0)sum[i]=1;
		if(ju[i]!=0){
			sum[ju[i]]+=sum[i];
			sum[i]=0;
		}else{
			sum[i+1]+=sum[i];
		}
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]+=sum[i];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
