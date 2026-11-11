#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int ans=1,n;
long long m,a[N],tot,p[N];
void find(int x){
	int l=0,r=x+1,mid;
	while(l+1<r){
		mid=(l+r)>>1;
		if(mid>0&&1ll*(x-mid+1)*a[x]-(p[x]-p[mid-1])<=m){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	ans=max(ans,(x-r+1));
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+a[i];
	}
	for(long long i=2;i<=n;i++){
		find(i);
	}
	cout<<ans;
	return 0;
}

