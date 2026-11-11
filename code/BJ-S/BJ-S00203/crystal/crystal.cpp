#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],l,r,mid;
bool check(int x){
	if(x>n)return 0;
	int L=1,R=x,opt=0;
	for(int i=L;i<=R;i++){
		opt+=a[R]-a[i];
	}
	while(R<n){
		if(opt<=m)return 1;
		opt-=a[R]-a[L];
		opt+=(x-1)*(a[R+1]-a[R]);
		R++;L++;
	}
	if(opt<=m)return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	l=0,r=5e5+5;
    while(l<r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	cout<<l-1;
	return 0;
}
