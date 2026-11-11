#include <bits/stdc++.h>
using namespace std;
//头尾和中间最大值以及是否为倍数 
#define int long long
#define maxn 2005
int c,t,n,d;
int a[maxn];
int val[3*maxn];
//void build(int u,int l,int r){
//	if(l==r){
//		val[u]=a[l];
//		return;
//	}
//	int mid=(l+r)/2;
//	build(u*2,l,mid);
//	build(u*2+1,mid+1,r);
//	val[u]=min(val[u*2],val[u*2+1]);
//}
//int query(int u,int l,int r,int s,int t){
//	if(s<=l&&r<=t)return val[u];
//	
//	if(t<=mid)return query(u*2,l,mid,s,t);
//	if(s>mid)return query(u*2+1,mid+1,r,s,t);
//	return min(query(u*2,l,mid,s,t),query(u*2+1,mid+1,r,s,t));
//}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
	//	build(1,1,n);
		int ans=0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j<i-1;j++){
				bool flag=true;
				if((i-j+1)%2==1)continue;
				for(int k = j+1;k <= i;k++){
					if((a[k]-a[k-1])>=d){
						flag=false;
						break;
					}
				} 
				if(((a[i]-a[j+1])%d==0)&&((a[i-1]-a[j])%d==0)&&flag)ans++;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
