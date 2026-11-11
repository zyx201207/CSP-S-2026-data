#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}for(int i=1;i<=n;i++){
		int x=a[i]-a[i-1];
		int l=-1,r=i;
		while(l+1<r){
			int mid=(l+r)>>1;
			if((i-mid)*x-a[i]+a[mid]<=m){
				r=mid;
			}else{
				l=mid;
			}
		}ans=max(ans,i-r);
	}cout<<ans;
}/*
100pts
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
