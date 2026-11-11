#include<bits/stdc++.h>
#define up(i,j,k) for(int i=j;i<=k;i++)
#define da(i,j,k) for(int i=j;i<=k;i++)
#define ll long long
#define db double
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#define int long long
using namespace std;
const int N=5e5+5;
int n;
ll m;
ll a[N],sum[N];
ll calc(int x,int y){
	int z=y-x;
	return a[y]*z-(sum[y-1]-sum[x-1]);
}
ll maxx=1;
void deal(int x){
	int l=1,r=x;
	while(l<r){
		int mid=(r-l)/2+l;
//		cout<<mid<<" "<<x<<" "<<calc(mid,x)<<endl;
		if(calc(mid,x)<=m){
			maxx=max(maxx,1LL*x-mid+1);
			r=mid;
		}else l=mid+1;
	}
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	up(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	up(i,1,n) sum[i]=sum[i-1]+a[i];
	up(i,1,n){
		deal(i);
	}
	cout<<maxx;
	return 0;
}
/*

*/

