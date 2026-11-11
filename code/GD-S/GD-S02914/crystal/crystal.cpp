#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int vis[N];
int n,k;
int a[N];
int sum;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=1e5;
		vis[a[i]]++;
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	int vv=sum/n;
	int id=upper_bound(a+1,a+1+n,vv)-a;
	int tt=a[id];
	for(int i=id-1;i>=1;i--){
		k-=tt-a[i];
		if(k<0){
			k+=tt-a[i];
			break;
		}else{
			vis[a[id]]++;
			continue;
		}
	}
	int maxn=-1e18;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,vis[a[i]]);
	}
	cout<<maxn;
	return 0;
}
