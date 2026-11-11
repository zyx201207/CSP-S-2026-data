#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
ll n,m,a[N],b[N];
ll mx;
int mxx1;
ll k=1;
//int fa[N];
//int find(int x){
//	if(fa[x]!=x){
//		fa[x]=find(fa[x]);
//	}
//	return fa[x];
//}
bool cmp(int x,int y){
	return x>y;
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
		mx=max(mx,a[i]);
	}
//	for(int i=1;i<=n1;i++){
//		cout<<b[i]<<" ";
//	}
	for(;k<=mx;k++){
		ll n1=0;
		for(int i=1;i<=n;i++){
			if(a[i]<=k) b[++n1]=a[i];
		}
		ll sum=0;
		int cnt=0;
		sort(b+1,b+n1+1,cmp);
		for(int j=1;j<=n1;j++){
			if(m<sum+k-b[j]) break;
			sum+=k-b[j];
			cnt++;
		}
		mxx1=max(mxx1,cnt);
	}
	cout<<mxx1;
	return 0;
}
