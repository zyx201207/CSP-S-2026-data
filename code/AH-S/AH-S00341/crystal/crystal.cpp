#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e5+5;
int n,m,a[N],b[N],ans=1;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	int id=0;
	for(int i=1;i<=n;i++){
		if(m>=((i-id)*a[i]-(b[i]-b[id])))ans=max(ans,i-id);
		else 
			while(m<((i-id)*a[i]-(b[i]-b[id]))&&id<i)id++;
	}
	cout<<ans;
	return 0;
}
//m次操作使相同的数最多
