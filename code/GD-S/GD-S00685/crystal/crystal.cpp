#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,a[500010],m,cnt,zd,t,s[500010],L,R,mid;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>0;i--) s[i]=s[i+1]+a[n]-a[i];
	for(int i=1;i<=n;i++){
		L=0,R=i;
		while(L+1<R){
			mid=(L+R)/2;
			if(s[mid]-s[i]-(a[n]-a[i])*(i-mid+1)>m) L=mid;
			else R=mid;
		}
		zd=max(zd,i-R+1);
	}
	cout<<zd;
	return 0;
}
