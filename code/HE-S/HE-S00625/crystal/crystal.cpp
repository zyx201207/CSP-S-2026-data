#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m;
int a[N];
int b[N];
int cnt[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int k=0,res,z;
	for(int i=1;i<=n;i++){
		res=1;
		cnt[++k]=cnt[k-1]+1;
		z=a[i]-a[i-1];
		while(a[i]==a[i+1]){
			i++;
			cnt[k]++;
			res++;
		}
		b[k]=z*cnt[k-1]+b[k-1];
		//cout<<z*res<<" "<<b[k]<<"\n";
	}
	int l=1,ans=0;
	for(int i=1;i<=k;i++){
		while(l<i&&((b[i]-b[l-1])>m))l++;
		ans=max(cnt[i]-cnt[l-1],ans);
	}
	cout<<ans;
	return 0;
}
