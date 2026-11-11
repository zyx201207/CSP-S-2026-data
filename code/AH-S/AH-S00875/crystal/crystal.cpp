#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+15;
int a[N],s[N],n,m,maxn=1;

signed main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i];
sort(a+1,a+1+n);
for(int i=1;i<=n;i++) {s[i]=a[i]+s[i-1];}
   for(int i=1;i<=n;i++){
    int l=1,r=i;
	while(l<r){
		int mid=(l+r+1)/2;
		if(a[i]*mid-s[i]+s[i-mid]<=m) l=mid;
		else r=mid-1;
	//	cout<<mid<<' '<<a[i]*mid-s[i]+s[i-mid]<<' ';
	}
//	cout<<'\n';
	maxn=max(l,maxn);
}
cout<<maxn;
return 0;
}
