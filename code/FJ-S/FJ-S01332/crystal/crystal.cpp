#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],lt,rt,mid,ans;
inline int check(int x,int k){
	int sum=(x-k+1)*a[x]-(b[x]-b[k-1]);
	return sum<=m;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
		lt=1,rt=i-1;
		while(lt<=rt){
			mid=(lt+rt)>>1;
			if(check(i,mid)) rt=mid-1;
			else lt=mid+1;
		}
		ans=max(ans,i-lt+1);
	}
	cout<<ans;
	return 0;
}

