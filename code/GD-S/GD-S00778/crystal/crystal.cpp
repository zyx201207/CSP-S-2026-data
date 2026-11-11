#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int a[maxn];
int ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	int mid=(l+r)/2;
	while(l<=r){
		int cnt=0;
		bool f=true;
		int e=m;
		mid=(l+r)/2;
		for(int i=mid;i>=1;i--){
			if(a[mid]-a[i]>e){
				f=false;
				break;
			}
			cnt++;
			e-=a[mid]-a[i];
		}
		if(f){
			ans=max(ans,mid);
			l=mid+1;
		}
		else{
			ans=max(ans,cnt);
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
/*
5 5 
1 2 4 8 9 

3
--------分界线---------
5 8
-3 -1 2 2 7

4
--------分界线---------
5 9
7 8 9 10 11

4
--------分界线---------
5 0
2 1 2 3 2

3
*/
